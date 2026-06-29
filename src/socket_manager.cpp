# include "../include/socket_manager.h"
bool SocketManager :: initialize(){
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2,2),&wsaData);
    if(result !=0){
        std:: cout<<"WSASTARTUP failed\n";
        return false;
    } 
    std::cout<<"Winsock initialized successfully \n";
    return true;
}