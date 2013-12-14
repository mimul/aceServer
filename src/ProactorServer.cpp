#include "ace/Proactor.h"
#include "ace/Asynch_Acceptor.h"
#include "AsynServiceHandler.h"

int main()
{
    ACE_INET_Addr listenPort(32002);
    ACE_Asynch_Acceptor<AsynServerHandler> server;
    if(server.open(listenPort) == -1)
    {
        return -1;
    }

    ACE_Proactor::instance()->proactor_run_event_loop();
    return 0;
}
