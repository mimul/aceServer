#include <stdio.h>

#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ServiceHandler.h"

int main(int argc, char* argv[])
{
    ACE_INET_Addr listenPort(32001);
    ClientAcceptor ca;
    if(ca.open(listenPort) == -1)
    {
        return -1;
    }
    ACE_Reactor::instance()->run_reactor_event_loop();
    return 0;
}
