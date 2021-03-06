/*
 *  mms_client_read.c
 *
 *  Copyright 2013 Michael Zillgith
 *
 *	This file is part of libIEC61850.
 *
 *	libIEC61850 is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	libIEC61850 is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *	See COPYING file for the complete license text.
 */

#include "libiec61850_platform_includes.h"
#include <MmsPdu.h>
#include "mms_common.h"
#include "mms_client_connection.h"
#include "byte_buffer.h"
#include "stack_config.h"

#include "platform_endian.h"

#include "mms_client_internal.h"
#include "mms_common_internal.h"

void memcpyReverseByteOrder(uint8_t* dst, uint8_t* src, int size);

MmsValue*
mmsClient_parseListOfAccessResults(AccessResult_t** accessResultList, int listSize)
{
    MmsValue* valueList = NULL;
    MmsValue* value = NULL;
    MmsIndication retVal = MMS_OK;

    int elementCount = listSize;

    if (elementCount > 1)
        valueList = MmsValue_createEmtpyArray(elementCount);

    int i = 0;

    for (i = 0; i < elementCount; i++) {
        AccessResult_PR presentType = accessResultList[i]->present;

        if (presentType == AccessResult_PR_failure) {
            if (DEBUG) printf("access error!\n");

            retVal = MMS_ERROR;
        }
        else if (presentType == AccessResult_PR_array) {
            value = (MmsValue*) calloc(1, sizeof(MmsValue));
            value->type = MMS_ARRAY;

            int elementCount =
                    accessResultList[i]->choice.array.list.count;

            value->value.structure.size = elementCount;
            value->value.structure.components = (MmsValue**) calloc(elementCount, sizeof(MmsValue*));

            int j;

            for (j = 0; j < elementCount; j++) {
                value->value.structure.components[j] = mmsMsg_parseDataElement(
                        accessResultList[i]->choice.array.list.array[j]);
            }
        }
        else if (presentType == AccessResult_PR_structure) {
            value = (MmsValue*) calloc(1, sizeof(MmsValue));
            value->type = MMS_STRUCTURE;

            int componentCount =
                    accessResultList[i]->choice.structure.list.count;

            value->value.structure.size = componentCount;
            value->value.structure.components = (MmsValue**) calloc(componentCount, sizeof(MmsValue*));

            int j;
            for (j = 0; j < componentCount; j++) {
                value->value.structure.components[j] = mmsMsg_parseDataElement(
                        accessResultList[i]->choice.structure.list.array[j]);
            }
        }
        else if (presentType == AccessResult_PR_bitstring) {
            value = (MmsValue*) calloc(1, sizeof(MmsValue));
            value->type = MMS_BIT_STRING;
            int size = accessResultList[i]->choice.bitstring.size;

            value->value.bitString.size = (size * 8)
               - accessResultList[i]->choice.bitstring.bits_unused;

            value->value.bitString.buf = (uint8_t*) malloc(size);
            memcpy(value->value.bitString.buf,
                    accessResultList[i]->choice.bitstring.buf, size);

        }
        else if (presentType == AccessResult_PR_integer) {
            long integerValue;
            asn_INTEGER2long(&accessResultList[i]->choice.integer, &integerValue);
            value = MmsValue_newIntegerFromInt32((int32_t) integerValue);
        }
        else if (presentType == AccessResult_PR_unsigned) {
            Asn1PrimitiveValue* berInteger =
                    BerInteger_createFromBuffer(accessResultList[i]->choice.integer.buf,
                            accessResultList[i]->choice.integer.size);
            value = MmsValue_newIntegerFromBerInteger(berInteger);
        }
        else if (presentType == AccessResult_PR_floatingpoint) {
            int size = accessResultList[i]->choice.floatingpoint.size;

            value = (MmsValue*) calloc(1, sizeof(MmsValue));
            value->type = MMS_FLOAT;

            if (size == 5) { /* FLOAT32 */
                value->value.floatingPoint.formatWidth = 32;
                value->value.floatingPoint.exponentWidth = accessResultList[i]->choice.floatingpoint.buf[0];

                uint8_t* floatBuf = (accessResultList[i]->choice.floatingpoint.buf + 1);

                value->value.floatingPoint.buf = (uint8_t*) malloc(4);

#ifdef ORDER_LITTLE_ENDIAN
                    memcpyReverseByteOrder(value->value.floatingPoint.buf, floatBuf, 4);
#else
                    memcpy(value->value.floatingPoint.buf, floatBuf, 4);
#endif

            }

            if (size == 9) { /* FLOAT64 */
                value->value.floatingPoint.formatWidth = 64;
                value->value.floatingPoint.exponentWidth = accessResultList[i]->choice.floatingpoint.buf[0];

                uint8_t* floatBuf = (accessResultList[i]->choice.floatingpoint.buf + 1);

                value->value.floatingPoint.buf = (uint8_t*) malloc(8);

#ifdef ORDER_LITTLE_ENDIAN
                    memcpyReverseByteOrder(value->value.floatingPoint.buf, floatBuf, 8);
#else
                    memcpy(value->value.floatingPoint.buf, floatBuf, 8);
#endif
            }

        }
        else if (presentType == AccessResult_PR_visiblestring) {
            value = (MmsValue*) calloc(1, sizeof(MmsValue));

            value->type = MMS_VISIBLE_STRING;


            int strSize = accessResultList[i]->choice.visiblestring.size;

            value->value.visibleString = (char*) malloc(strSize + 1);

            memcpy(value->value.visibleString,
                    accessResultList[i]->choice.visiblestring.buf,
                    strSize);

            value->value.visibleString[strSize] = 0;
        }
        else if (presentType == AccessResult_PR_utctime) {
            value = (MmsValue*) calloc(1, sizeof(MmsValue));

            value->type = MMS_UTC_TIME;
            memcpy(value->value.utcTime,
                    accessResultList[i]->choice.utctime.buf, 8);
        }
        else if (presentType == AccessResult_PR_boolean) {
            value = MmsValue_newBoolean(accessResultList[i]->choice.boolean);
        }
        else if (presentType == AccessResult_PR_binarytime) {
            int size = accessResultList[i]->choice.binarytime.size;

            if (size <= 6) {
                value = (MmsValue*) calloc(1, sizeof(MmsValue));
                value->type = MMS_BINARY_TIME;
                value->value.binaryTime.size = size;
                memcpy(value->value.binaryTime.buf, accessResultList[i]->choice.binarytime.buf, size);
            }
        }
        else {
            printf("unknown type %i\n", presentType);
            retVal = MMS_ERROR;
        }

        if (elementCount > 1)
            MmsValue_setElement(valueList, i, value);
    }

    if (valueList == NULL)
        valueList = value;

    return valueList;
}


MmsValue*
mmsClient_parseReadResponse(ByteBuffer* message, uint32_t* invokeId)
{
	MmsPdu_t* mmsPdu = 0; /* allow asn1c to allocate structure */
	MmsIndication retVal =  MMS_OK;

	MmsValue* valueList = NULL;

	asn_dec_rval_t rval;

	rval = ber_decode(NULL, &asn_DEF_MmsPdu,
			(void**) &mmsPdu, ByteBuffer_getBuffer(message), ByteBuffer_getSize(message));

	if (DEBUG) xer_fprint(stdout, &asn_DEF_MmsPdu, mmsPdu);

	if (mmsPdu->present == MmsPdu_PR_confirmedResponsePdu) {

		*invokeId = mmsClient_getInvokeId(&mmsPdu->choice.confirmedResponsePdu);

		if (mmsPdu->choice.confirmedResponsePdu.confirmedServiceResponse.present == ConfirmedServiceResponse_PR_read) {
			ReadResponse_t* response = &(mmsPdu->choice.confirmedResponsePdu.confirmedServiceResponse.choice.read);

			int elementCount = response->listOfAccessResult.list.count;

			valueList = mmsClient_parseListOfAccessResults(response->listOfAccessResult.list.array,
			        elementCount);
		}
		else {
			retVal = MMS_ERROR;
		}
	}
	else {
		retVal = MMS_ERROR;
	}

	asn_DEF_MmsPdu.free_struct(&asn_DEF_MmsPdu, mmsPdu, 0);

	return valueList;
}


static ReadRequest_t*
createReadRequest (MmsPdu_t* mmsPdu) {
	mmsPdu->choice.confirmedRequestPdu.confirmedServiceRequest.present =
				ConfirmedServiceRequest_PR_read;

	return &(mmsPdu->choice.confirmedRequestPdu.confirmedServiceRequest.choice.read);
}


int
mmsClient_createReadNamedVariableListRequest(uint32_t invokeId, char* domainId, char* itemId,
		ByteBuffer* writeBuffer, bool specWithResult)
{
	MmsPdu_t* mmsPdu = mmsClient_createConfirmedRequestPdu(invokeId);

	ReadRequest_t* readRequest = createReadRequest(mmsPdu);

	if (specWithResult) {
		readRequest->specificationWithResult = (BOOLEAN_t*) calloc(1, sizeof(BOOLEAN_t));
		*(readRequest->specificationWithResult) = true;
	}
	else
		readRequest->specificationWithResult = NULL;

	readRequest->variableAccessSpecification.present = VariableAccessSpecification_PR_variableListName;

	ObjectName_t* objectName = &(readRequest->variableAccessSpecification.choice.variableListName);

	objectName->present = ObjectName_PR_domainspecific;

	objectName->choice.domainspecific.domainId.buf = (uint8_t*) copyString(domainId);
	objectName->choice.domainspecific.domainId.size = strlen(domainId);

	objectName->choice.domainspecific.itemId.buf = (uint8_t*) copyString(itemId);
	objectName->choice.domainspecific.itemId.size = strlen(itemId);

	asn_enc_rval_t rval;

	rval = der_encode(&asn_DEF_MmsPdu, mmsPdu,
	          (asn_app_consume_bytes_f (__cdecl *))  mmsClient_write_out, (void*) writeBuffer);

	asn_DEF_MmsPdu.free_struct(&asn_DEF_MmsPdu, mmsPdu, 0);

	return rval.encoded;
}

int
mmsClient_createReadAssociationSpecificNamedVariableListRequest(
		uint32_t invokeId,
		char* itemId,
		ByteBuffer* writeBuffer,
		bool specWithResult)
{
	MmsPdu_t* mmsPdu = mmsClient_createConfirmedRequestPdu(invokeId);

	ReadRequest_t* readRequest = createReadRequest(mmsPdu);

	if (specWithResult) {
		readRequest->specificationWithResult = (BOOLEAN_t*) calloc(1, sizeof(BOOLEAN_t));
		*(readRequest->specificationWithResult) = true;
	}
	else
		readRequest->specificationWithResult = NULL;

	readRequest->variableAccessSpecification.present = VariableAccessSpecification_PR_variableListName;

	ObjectName_t* objectName = &(readRequest->variableAccessSpecification.choice.variableListName);

	objectName->present = ObjectName_PR_aaspecific;

	objectName->choice.aaspecific.buf = (uint8_t*) copyString(itemId);
	objectName->choice.aaspecific.size = strlen(itemId);

	asn_enc_rval_t rval;

	rval = der_encode(&asn_DEF_MmsPdu, mmsPdu,
	          (asn_app_consume_bytes_f (__cdecl *))  mmsClient_write_out, (void*) writeBuffer);

	asn_DEF_MmsPdu.free_struct(&asn_DEF_MmsPdu, mmsPdu, 0);

	return rval.encoded;
}

/**
 * Request a single value
 */
int
mmsClient_createReadRequest(char* domainId, char* itemId, ByteBuffer* writeBuffer)
{
	MmsPdu_t* mmsPdu = mmsClient_createConfirmedRequestPdu(1);

	ReadRequest_t* readRequest = createReadRequest(mmsPdu);

	readRequest->specificationWithResult = NULL;

	readRequest->variableAccessSpecification.present = VariableAccessSpecification_PR_listOfVariable;

	readRequest->variableAccessSpecification.choice.listOfVariable.list.array = (ListOfVariableSeq **) calloc(1, sizeof(ListOfVariableSeq_t*));
	readRequest->variableAccessSpecification.choice.listOfVariable.list.count = 1;

	ListOfVariableSeq_t* listOfVars = (ListOfVariableSeq_t*) calloc(1, sizeof(ListOfVariableSeq_t));

	readRequest->variableAccessSpecification.choice.listOfVariable.list.array[0] = listOfVars;

	listOfVars->alternateAccess = NULL;
	listOfVars->variableSpecification.present = VariableSpecification_PR_name;
	listOfVars->variableSpecification.choice.name.present = ObjectName_PR_domainspecific;
	listOfVars->variableSpecification.choice.name.choice.domainspecific.domainId.buf = (uint8_t*) domainId;
	listOfVars->variableSpecification.choice.name.choice.domainspecific.domainId.size = strlen(domainId);
	listOfVars->variableSpecification.choice.name.choice.domainspecific.itemId.buf = (uint8_t*) itemId;
	listOfVars->variableSpecification.choice.name.choice.domainspecific.itemId.size = strlen(itemId);

	asn_enc_rval_t rval;

	rval = der_encode(&asn_DEF_MmsPdu, mmsPdu,
	           (asn_app_consume_bytes_f (__cdecl *)) mmsClient_write_out, (void*) writeBuffer);

	/* clean up data structures */
	free(listOfVars);
	free(readRequest->variableAccessSpecification.choice.listOfVariable.list.array);
	readRequest->variableAccessSpecification.choice.listOfVariable.list.array = NULL;
	readRequest->variableAccessSpecification.choice.listOfVariable.list.count = 0;
	asn_DEF_MmsPdu.free_struct(&asn_DEF_MmsPdu, mmsPdu, 0);

	return rval.encoded;
}

static AlternateAccess_t*
createAlternateAccess(uint32_t index, uint32_t elementCount)
{
	AlternateAccess_t* alternateAccess = (AlternateAccess_t*) calloc(1, sizeof(AlternateAccess_t));
	alternateAccess->list.count = 1;
	alternateAccess->list.array = (AlternateAccess__Member **) calloc(1, sizeof(struct AlternateAccess__Member*));
	alternateAccess->list.array[0] = (AlternateAccess__Member *) calloc(1, sizeof(struct AlternateAccess__Member));
	alternateAccess->list.array[0]->present = AlternateAccess__Member_PR_unnamed;

	alternateAccess->list.array[0]->choice.unnamed = (AlternateAccessSelection *) calloc(1, sizeof(AlternateAccessSelection_t));

	alternateAccess->list.array[0]->choice.unnamed->present = AlternateAccessSelection_PR_selectAccess;

	if (elementCount > 0) {
		alternateAccess->list.array[0]->choice.unnamed->choice.selectAccess.present =
				AlternateAccessSelection__selectAccess_PR_indexRange;

		INTEGER_t* asnIndex =
			&(alternateAccess->list.array[0]->choice.unnamed->choice.selectAccess.choice.indexRange.lowIndex);

		asn_long2INTEGER(asnIndex, index);

		asnIndex =
			&(alternateAccess->list.array[0]->choice.unnamed->choice.selectAccess.choice.indexRange.numberOfElements);

		asn_long2INTEGER(asnIndex, elementCount);
	}
	else {
		alternateAccess->list.array[0]->choice.unnamed->choice.selectAccess.present =
				AlternateAccessSelection__selectAccess_PR_index;

		INTEGER_t* asnIndex =
			&(alternateAccess->list.array[0]->choice.unnamed->choice.selectAccess.choice.index);

		asn_long2INTEGER(asnIndex, index);
	}

	return alternateAccess;
}

static ListOfVariableSeq_t*
createVariableIdentifier(char* domainId, char* itemId)
{
	ListOfVariableSeq_t* variableIdentifier = (ListOfVariableSeq_t*) calloc(1, sizeof(ListOfVariableSeq_t));

	variableIdentifier->variableSpecification.present = VariableSpecification_PR_name;
	variableIdentifier->variableSpecification.choice.name.present = ObjectName_PR_domainspecific;
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.domainId.buf = (uint8_t*) domainId;
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.domainId.size = strlen(domainId);
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.itemId.buf = (uint8_t*) itemId;
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.itemId.size = strlen(itemId);

	return variableIdentifier;
}

int
mmsClient_createReadRequestAlternateAccessIndex(char* domainId, char* itemId,
		uint32_t index, uint32_t elementCount, ByteBuffer* writeBuffer)
{
	MmsPdu_t* mmsPdu = mmsClient_createConfirmedRequestPdu(1);
	ReadRequest_t* readRequest = createReadRequest(mmsPdu);

	readRequest->specificationWithResult = NULL;

	readRequest->variableAccessSpecification.present = VariableAccessSpecification_PR_listOfVariable;

	readRequest->variableAccessSpecification.choice.listOfVariable.list.array = (ListOfVariableSeq **) calloc(1, sizeof(ListOfVariableSeq_t*));
	readRequest->variableAccessSpecification.choice.listOfVariable.list.count = 1;

	ListOfVariableSeq_t* variableIdentifier = createVariableIdentifier(domainId, itemId);

	readRequest->variableAccessSpecification.choice.listOfVariable.list.array[0] = variableIdentifier;

	variableIdentifier->alternateAccess = createAlternateAccess(index, elementCount);

	asn_enc_rval_t rval;

	rval = der_encode(&asn_DEF_MmsPdu, mmsPdu,
	           (asn_app_consume_bytes_f (__cdecl *)) mmsClient_write_out, (void*) writeBuffer);

	if (DEBUG) xer_fprint(stdout, &asn_DEF_MmsPdu, mmsPdu);

	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.domainId.buf = 0;
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.domainId.size = 0;
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.itemId.buf = 0;
	variableIdentifier->variableSpecification.choice.name.choice.domainspecific.itemId.size = 0;

	asn_DEF_MmsPdu.free_struct(&asn_DEF_MmsPdu, mmsPdu, 0);

	return rval.encoded;
}

static ListOfVariableSeq_t**
createListOfVariables(ReadRequest_t* readRequest, int valuesCount) {
	readRequest->variableAccessSpecification.present = VariableAccessSpecification_PR_listOfVariable;

	readRequest->variableAccessSpecification.choice.listOfVariable.list.array =
				(ListOfVariableSeq **) calloc(valuesCount, sizeof(ListOfVariableSeq_t*));
	readRequest->variableAccessSpecification.choice.listOfVariable.list.count = valuesCount;
	readRequest->variableAccessSpecification.choice.listOfVariable.list.size = valuesCount;

	return readRequest->variableAccessSpecification.choice.listOfVariable.list.array;
}

/**
 * Request multiple values of a single domain
 */
int
mmsClient_createReadRequestMultipleValues(char* domainId, LinkedList items,
		ByteBuffer* writeBuffer)
{
	MmsPdu_t* mmsPdu = mmsClient_createConfirmedRequestPdu(1);

	ReadRequest_t* readRequest = createReadRequest(mmsPdu);

	readRequest->specificationWithResult = NULL;

	int valuesCount = LinkedList_size(items);

	ListOfVariableSeq_t** listOfVars = createListOfVariables(readRequest, valuesCount);

	LinkedList item = items;
	char* itemId;
	int i = 0;

	while ((item = LinkedList_getNext(item)) != NULL) {
		itemId = (char*) (item->data);
		listOfVars[i] = createVariableIdentifier(domainId, itemId);
		i++;
	}

	asn_enc_rval_t rval;

	rval = der_encode(&asn_DEF_MmsPdu, mmsPdu,
	           (asn_app_consume_bytes_f (__cdecl *)) mmsClient_write_out, (void*) writeBuffer);

	if (DEBUG) xer_fprint(stdout, &asn_DEF_MmsPdu, mmsPdu);

	for (i = 0; i < valuesCount; i++) {
		free(listOfVars[i]);
	}
	free(listOfVars);

	readRequest->variableAccessSpecification.choice.listOfVariable.list.count = 0;
	readRequest->variableAccessSpecification.choice.listOfVariable.list.size = 0;
	readRequest->variableAccessSpecification.choice.listOfVariable.list.array = NULL;


	asn_DEF_MmsPdu.free_struct(&asn_DEF_MmsPdu, mmsPdu, 0);

	return rval.encoded;
}

