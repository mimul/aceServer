CPP 		= g++
ACE_ROOT	= /home/vagrant/ACE_wrappers
INCLUDE         =       -I. -I${ACE_ROOT} -I/home/vagrant/include
LIBS            =       -L/home/vagrant/lib -L$(ACE_ROOT)/ace -lACE

SERVER 		= ServiceHandler.cpp ReactorServer.cpp
ASYNCSERVER 	= AsynServiceHandler.cpp ProactorServer.cpp

server : $(SERVER)
	$(CPP) $(SERVER) $(LIBS) $(INCLUDE) -o server
asyncserver : $(ASYNCSERVER)
	$(CPP) $(ASYNCSERVER) $(LIBS) $(INCLUDE) -o asyncserver
