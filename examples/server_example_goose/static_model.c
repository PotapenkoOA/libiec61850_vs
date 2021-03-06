/*
 * static_model.c
 *
 * automatically generated from simpleIO_direct_control_goose.scd
 */
#include <stdlib.h>
#include "model.h"

IedModel iedModel;
static DataSet* datasets[];
static ReportControlBlock* reportControlBlocks[];
static GSEControlBlock* gseControlBlocks[];
static void initializeValues();
LogicalDevice iedModel_GenericIO;
LogicalNode   iedModel_GenericIO_LLN0;
DataObject    iedModel_GenericIO_LLN0_Mod;
DataAttribute iedModel_GenericIO_LLN0_Mod_q;
DataAttribute iedModel_GenericIO_LLN0_Mod_t;
DataAttribute iedModel_GenericIO_LLN0_Mod_ctlModel;
DataObject    iedModel_GenericIO_LLN0_Beh;
DataAttribute iedModel_GenericIO_LLN0_Beh_stVal;
DataAttribute iedModel_GenericIO_LLN0_Beh_q;
DataAttribute iedModel_GenericIO_LLN0_Beh_t;
DataObject    iedModel_GenericIO_LLN0_Health;
DataAttribute iedModel_GenericIO_LLN0_Health_stVal;
DataAttribute iedModel_GenericIO_LLN0_Health_q;
DataAttribute iedModel_GenericIO_LLN0_Health_t;
DataObject    iedModel_GenericIO_LLN0_NamPlt;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_vendor;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_swRev;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_d;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_configRev;
DataAttribute iedModel_GenericIO_LLN0_NamPlt_ldNs;
LogicalNode   iedModel_GenericIO_LPHD1;
DataObject    iedModel_GenericIO_LPHD1_PhyNam;
DataAttribute iedModel_GenericIO_LPHD1_PhyNam_vendor;
DataObject    iedModel_GenericIO_LPHD1_PhyHealth;
DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_stVal;
DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_q;
DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_t;
DataObject    iedModel_GenericIO_LPHD1_Proxy;
DataAttribute iedModel_GenericIO_LPHD1_Proxy_stVal;
DataAttribute iedModel_GenericIO_LPHD1_Proxy_q;
DataAttribute iedModel_GenericIO_LPHD1_Proxy_t;
LogicalNode   iedModel_GenericIO_GGIO1;
DataObject    iedModel_GenericIO_GGIO1_Mod;
DataAttribute iedModel_GenericIO_GGIO1_Mod_q;
DataAttribute iedModel_GenericIO_GGIO1_Mod_t;
DataAttribute iedModel_GenericIO_GGIO1_Mod_ctlModel;
DataObject    iedModel_GenericIO_GGIO1_Beh;
DataAttribute iedModel_GenericIO_GGIO1_Beh_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Beh_q;
DataAttribute iedModel_GenericIO_GGIO1_Beh_t;
DataObject    iedModel_GenericIO_GGIO1_Health;
DataAttribute iedModel_GenericIO_GGIO1_Health_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Health_q;
DataAttribute iedModel_GenericIO_GGIO1_Health_t;
DataObject    iedModel_GenericIO_GGIO1_NamPlt;
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_vendor;
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_swRev;
DataAttribute iedModel_GenericIO_GGIO1_NamPlt_d;
DataObject    iedModel_GenericIO_GGIO1_AnIn1;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn1_t;
DataObject    iedModel_GenericIO_GGIO1_AnIn2;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn2_t;
DataObject    iedModel_GenericIO_GGIO1_AnIn3;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn3_t;
DataObject    iedModel_GenericIO_GGIO1_AnIn4;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag_f;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_q;
DataAttribute iedModel_GenericIO_GGIO1_AnIn4_t;
DataObject    iedModel_GenericIO_GGIO1_SPCSO1;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_ctlModel;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_t;
DataObject    iedModel_GenericIO_GGIO1_SPCSO2;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_ctlModel;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_t;
DataObject    iedModel_GenericIO_GGIO1_SPCSO3;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_ctlModel;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_t;
DataObject    iedModel_GenericIO_GGIO1_SPCSO4;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_stVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_q;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_T;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Test;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Check;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_ctlModel;
DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_t;
DataObject    iedModel_GenericIO_GGIO1_Ind1;
DataAttribute iedModel_GenericIO_GGIO1_Ind1_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind1_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind1_t;
DataObject    iedModel_GenericIO_GGIO1_Ind2;
DataAttribute iedModel_GenericIO_GGIO1_Ind2_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind2_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind2_t;
DataObject    iedModel_GenericIO_GGIO1_Ind3;
DataAttribute iedModel_GenericIO_GGIO1_Ind3_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind3_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind3_t;
DataObject    iedModel_GenericIO_GGIO1_Ind4;
DataAttribute iedModel_GenericIO_GGIO1_Ind4_stVal;
DataAttribute iedModel_GenericIO_GGIO1_Ind4_q;
DataAttribute iedModel_GenericIO_GGIO1_Ind4_t;

IedModel iedModel = {
    "simpleIO",
    &iedModel_GenericIO,
    datasets,
    reportControlBlocks,
    gseControlBlocks,
    initializeValues
};

LogicalDevice iedModel_GenericIO = {
    "simpleIOGenericIO",
    NULL,
    &iedModel_GenericIO_LLN0
};

LogicalNode iedModel_GenericIO_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    &iedModel_GenericIO,
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
};

DataObject iedModel_GenericIO_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_q,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod_ctlModel,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_LLN0_Mod,
    NULL,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataObject iedModel_GenericIO_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Beh,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_GenericIO_LLN0,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    (ModelNode*) &iedModel_GenericIO_LLN0_Health_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LLN0_Health,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_GenericIO_LLN0,
    NULL,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_vendor,
    0,
    0
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_swRev,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_d,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_configRev,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt_ldNs,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &iedModel_GenericIO_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    0,
    EX,
    VISIBLE_STRING_255,
    NULL
};

LogicalNode iedModel_GenericIO_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    &iedModel_GenericIO,
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam,
};

DataObject iedModel_GenericIO_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam_vendor,
    0,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataObject iedModel_GenericIO_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_GenericIO_LPHD1,
    NULL,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

LogicalNode iedModel_GenericIO_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    &iedModel_GenericIO,
    NULL,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
};

DataObject iedModel_GenericIO_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_q,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod_ctlModel,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Mod,
    NULL,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Beh,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_q,
    NULL,
    0,
    0,
    ST,
    INT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Health,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_vendor,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_swRev,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt_d,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_GenericIO_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    0,
    DC,
    VISIBLE_STRING_255,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn1 = {
    DataObjectModelType,
    "AnIn1",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn1,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn2 = {
    DataObjectModelType,
    "AnIn2",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn2,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn3 = {
    DataObjectModelType,
    "AnIn3",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn3,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_AnIn4 = {
    DataObjectModelType,
    "AnIn4",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_q,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag_f,
    0,
    0,
    MX,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_mag,
    NULL,
    NULL,
    0,
    0,
    MX,
    FLOAT32,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4_t,
    NULL,
    0,
    0,
    MX,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_AnIn4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_AnIn4,
    NULL,
    NULL,
    0,
    0,
    MX,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO2 = {
    DataObjectModelType,
    "SPCSO2",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO2,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO3 = {
    DataObjectModelType,
    "SPCSO3",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO3,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_SPCSO4 = {
    DataObjectModelType,
    "SPCSO4",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_ctlModel,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat,
    0,
    0,
    CO,
    CONSTRUCTED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent,
    NULL,
    0,
    0,
    CO,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_origin,
    NULL,
    NULL,
    0,
    0,
    CO,
    OCTET_STRING_64,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_T,
    NULL,
    0,
    0,
    CO,
    INT8U,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_Test,
    NULL,
    0,
    0,
    CO,
    TIMESTAMP,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper_Check,
    NULL,
    0,
    0,
    CO,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_Oper,
    NULL,
    NULL,
    0,
    0,
    CO,
    CHECK,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4_t,
    NULL,
    0,
    0,
    CF,
    ENUMERATED,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_SPCSO4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_SPCSO4,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Ind2 = {
    DataObjectModelType,
    "Ind2",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind2,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Ind3 = {
    DataObjectModelType,
    "Ind3",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind3,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

DataObject iedModel_GenericIO_GGIO1_Ind4 = {
    DataObjectModelType,
    "Ind4",
    (ModelNode*) &iedModel_GenericIO_GGIO1,
    NULL,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_stVal,
    0,
    0
};

DataAttribute iedModel_GenericIO_GGIO1_Ind4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_q,
    NULL,
    0,
    0,
    ST,
    BOOLEAN,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4_t,
    NULL,
    0,
    0,
    ST,
    QUALITY,
    NULL
};

DataAttribute iedModel_GenericIO_GGIO1_Ind4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_GenericIO_GGIO1_Ind4,
    NULL,
    NULL,
    0,
    0,
    ST,
    TIMESTAMP,
    NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda0 = {
  "simpleIOGenericIO",
  "GGIO1$ST$SPCSO1$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda1 = {
  "simpleIOGenericIO",
  "GGIO1$ST$SPCSO2$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda2 = {
  "simpleIOGenericIO",
  "GGIO1$ST$SPCSO3$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_Events_fcda3 = {
  "simpleIOGenericIO",
  "GGIO1$ST$SPCSO4$stVal",
  -1,
  NULL,
  NULL
};

static DataSetEntry* ds_GenericIO_LLN0_Events_elements[4] = {
  &ds_GenericIO_LLN0_Events_fcda0,
  &ds_GenericIO_LLN0_Events_fcda1,
  &ds_GenericIO_LLN0_Events_fcda2,
  &ds_GenericIO_LLN0_Events_fcda3
};

static DataSet ds_GenericIO_LLN0_Events = {
  "simpleIOGenericIO",
  "LLN0$Events",
  4,
  ds_GenericIO_LLN0_Events_elements
};
static DataSetEntry ds_GenericIO_LLN0_AnalogValues_fcda0 = {
  "simpleIOGenericIO",
  "GGIO1$MX$AnIn1",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_AnalogValues_fcda1 = {
  "simpleIOGenericIO",
  "GGIO1$MX$AnIn2",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_AnalogValues_fcda2 = {
  "simpleIOGenericIO",
  "GGIO1$MX$AnIn3",
  -1,
  NULL,
  NULL
};

static DataSetEntry ds_GenericIO_LLN0_AnalogValues_fcda3 = {
  "simpleIOGenericIO",
  "GGIO1$MX$AnIn4",
  -1,
  NULL,
  NULL
};

static DataSetEntry* ds_GenericIO_LLN0_AnalogValues_elements[4] = {
  &ds_GenericIO_LLN0_AnalogValues_fcda0,
  &ds_GenericIO_LLN0_AnalogValues_fcda1,
  &ds_GenericIO_LLN0_AnalogValues_fcda2,
  &ds_GenericIO_LLN0_AnalogValues_fcda3
};

static DataSet ds_GenericIO_LLN0_AnalogValues = {
  "simpleIOGenericIO",
  "LLN0$AnalogValues",
  4,
  ds_GenericIO_LLN0_AnalogValues_elements
};

static DataSet* datasets[] = {
  &ds_GenericIO_LLN0_Events,
  &ds_GenericIO_LLN0_AnalogValues,
  NULL,
};
static ReportControlBlock iedModel_GenericIO_LLN0_report0 = {&iedModel_GenericIO_LLN0, "EventsRCB", "Events", false, "Events", 1, 16, 111, 50, 1000};
static ReportControlBlock iedModel_GenericIO_LLN0_report1 = {&iedModel_GenericIO_LLN0, "AnalogValuesRCB", "AnalogValues", false, "AnalogValues", 1, 16, 111, 50, 1000};

static ReportControlBlock* reportControlBlocks[] = {
    &iedModel_GenericIO_LLN0_report0,
    &iedModel_GenericIO_LLN0_report1,
    NULL
};

static PhyComAddress iedModel_GenericIO_LLN0_gse0_address = {
  4,
  111,
  1000,
  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x1}
};

static GSEControlBlock iedModel_GenericIO_LLN0_gse0 = {&iedModel_GenericIO_LLN0, "gcbEvents", "events", "Events", 1, false,&iedModel_GenericIO_LLN0_gse0_address};
static PhyComAddress iedModel_GenericIO_LLN0_gse1_address = {
  4,
  111,
  1000,
  {0x1, 0xc, 0xcd, 0x1, 0x0, 0x1}
};

static GSEControlBlock iedModel_GenericIO_LLN0_gse1 = {&iedModel_GenericIO_LLN0, "gcbAnalogValues", "analog", "AnalogValues", 1, false,&iedModel_GenericIO_LLN0_gse1_address};

static GSEControlBlock* gseControlBlocks[] = {
    &iedModel_GenericIO_LLN0_gse0,
    &iedModel_GenericIO_LLN0_gse1,
    NULL
};


static void
initializeValues()
{

iedModel_GenericIO_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

iedModel_GenericIO_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

iedModel_GenericIO_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GenericIO_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GenericIO_GGIO1_SPCSO3_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);

iedModel_GenericIO_GGIO1_SPCSO4_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(1);
}
