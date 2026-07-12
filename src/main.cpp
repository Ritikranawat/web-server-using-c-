# include "../include/socket_manager.h"
#include <iostream>
using namespace std;
int main(){
    SocketManager server;
    if(!server.initialize()){
        return 1;
    }
    if(!server.createSocket()){
        return 1;
    }
    if(!server.bindSocket()){
        return 1;
    }
    if(!server.startListening()){
        return 1;
    }
    if(!server.acceptClient()){
        return 1;
    }
    return 0;
}