/*
 *  socket_linux.c
 *
 *  Copyright 2013 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#include "socket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

#include <netinet/tcp.h> // required for TCP keepalive

#ifndef SOL_TCP
#define SOL_TCP IPPROTO_TCP
#endif

#include "stack_config.h"

struct sSocket {
    int fd;
};

struct sServerSocket {
    int fd;
    int backLog;
};

//TODO this is linux specific!
static void
activateKeepAlive(int sd)
{
    int optval;
    socklen_t optlen = sizeof(optval);

    optval = 1;
    setsockopt(sd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);

#if defined __linux__
    optval = CONFIG_TCP_KEEPALIVE_IDLE;
    setsockopt(sd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);

    optval = CONFIG_TCP_KEEPALIVE_INTERVAL;
    setsockopt(sd, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);

    optval = CONFIG_TCP_KEEPALIVE_CNT;
    setsockopt(sd, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
#endif
}

ServerSocket
TcpServerSocket_create(char* address, int port)
{
    ServerSocket serverSocket = NULL;

    int fd;

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) >= 0) {
        struct sockaddr_in serverAddress;

        memset(&serverAddress, 0, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY );
        serverAddress.sin_port = htons(port);

        //TODO check if this works with BSD
        int optionReuseAddr = 1;
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &optionReuseAddr, sizeof(int));

        if (bind(fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) >= 0) {
            serverSocket = malloc(sizeof(struct sServerSocket));
            serverSocket->fd = fd;
            serverSocket->backLog = 0;
        }
        else {
            close(fd);
            return NULL ;
        }

#if (CONFIG_ACTIVATE_TCP_KEEPALIVE == 1)
        activateKeepAlive(fd);
#endif
    }

    return serverSocket;
}

void
ServerSocket_listen(ServerSocket socket)
{
    listen(socket->fd, socket->backLog);
}

Socket
ServerSocket_accept(ServerSocket socket)
{
    int fd;

    Socket conSocket = NULL;

    fd = accept(socket->fd, NULL, NULL );

    if (fd >= 0) {
        conSocket = TcpSocket_create();
        conSocket->fd = fd;
    }

    return conSocket;
}

void
ServerSocket_setBacklog(ServerSocket socket, int backlog)
{
    socket->backLog = backlog;
}

static void
closeAndShutdownSocket(int socketFd)
{
    if (socketFd != -1) {
        // shutdown is required to unblock read or accept in another thread!
        int res = shutdown(socketFd, SHUT_RDWR);

        close(socketFd);
    }
}

void
ServerSocket_destroy(ServerSocket socket)
{
    closeAndShutdownSocket(socket->fd);

    free(socket);
}

Socket
TcpSocket_create()
{
    Socket socket = malloc(sizeof(struct sSocket));

    socket->fd = -1;

    return socket;
}

int
Socket_connect(Socket self, char* address, int port)
{
    struct hostent *server;
    struct sockaddr_in serverAddress;

    server = gethostbyname(address);

    memset((char *) &serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;

    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    serverAddress.sin_port = htons(port);

    self->fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(self->fd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
        return 0;
    else
        return 1;
}

char*
Socket_getPeerAddress(Socket self)
{
    struct sockaddr_storage addr;
    int addrLen = sizeof(addr);

    getpeername(self->fd, &addr, &addrLen);

    char* addrString[INET6_ADDRSTRLEN + 7];
    int port;

    if (addr.ss_family == AF_INET) {
        struct sockaddr_in* ipv4Addr = (struct sockaddr_in*) &addr;
        port = ntohs(ipv4Addr->sin_port);
        inet_ntop(AF_INET, &(ipv4Addr->sin_addr), addrString, INET_ADDRSTRLEN);
    }
    else if (addr.ss_family == AF_INET6) {
        struct sockaddr_in6* ipv6Addr = (struct sockaddr_in6*) &addr;
        port = ntohs(ipv6Addr->sin6_port);
        inet_ntop(AF_INET6, &(ipv6Addr->sin6_addr), addrString, INET6_ADDRSTRLEN);
    }
    else
        return NULL ;

    char* clientConnection = malloc(strlen(addrString) + 8);

    sprintf(clientConnection, "%s[%i]", addrString, port);

    return clientConnection;
}

int
Socket_read(Socket socket, uint8_t* buf, int size)
{
    return read(socket->fd, buf, size);
}

int
Socket_write(Socket socket, uint8_t* buf, int size)
{
    // MSG_NOSIGNAL - prevent send to signal SIGPIPE when peer unexpectedly closed the socket
    return send(socket->fd, buf, size, MSG_NOSIGNAL);
}

void
Socket_destroy(Socket socket)
{
    closeAndShutdownSocket(socket->fd);

    /* Wait for other threads to realize that the socket has been closed */
    Thread_sleep(100);

    free(socket);
}
