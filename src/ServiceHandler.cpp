#include "ServiceHandler.h"

int ServerHandler::open(void* p)
{
    if(super::open(p) == -1)
    {
        return -1;
    }

    ACE_INET_Addr peer_addr;
    if(this->peer().get_remote_addr(peer_addr)==0 &&
        peer_addr.addr_to_string(peer_name,MAXHOSTNAMELEN)==0)
    {
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Connection from %s\n"), peer_name));
    }
    return 0;
}

int ServerHandler::handle_input(ACE_HANDLE fd)
{
    const int INPUT_SIZE = 4096;
    char buffer[INPUT_SIZE];
    memset(buffer,0,INPUT_SIZE);

    int recvBytes = this->peer().recv(buffer,sizeof(buffer));

    if(recvBytes <= 0)
    {
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Connection close from %s\n"), peer_name));
        return -1;
    }
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Receive msg from %s: %s\n"), peer_name, buffer));
    this->peer().send(buffer, recvBytes);
    
    return 0;
}

int ServerHandler::handle_close(ACE_HANDLE fd, ACE_Reactor_Mask mask) {
    if (mask == ACE_Event_Handler::WRITE_MASK) {
        return 0;
    }

    return super::handle_close(fd, mask);
}
