# include "../include/socket_manager.h"
int main(){
    SocketManager server;
    if(!server.initialize()){
        return 1;
    }
    return 0 ;
}