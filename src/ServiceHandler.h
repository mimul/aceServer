#ifndef SERVER_HANDLER_H
#define SERVER_HANDLER_H

#include <cstdlib>
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"

class ServerHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
    typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> super;
    public:
        int open(void* = 0);
        virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
        virtual int handle_close(ACE_HANDLE fd, ACE_Reactor_Mask mask);
    private:
        ACE_TCHAR peer_name[MAXHOSTNAMELEN];
};

typedef ACE_Acceptor<ServerHandler, ACE_SOCK_ACCEPTOR> ClientAcceptor;

#endif //SERVER_HANDLER_H
