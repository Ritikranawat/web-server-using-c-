using namespace std;
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
bool SocketManager :: createSocket(){
    serverSocket = socket(
        AF_INET,
        SOCK_STREAM,
        IPPROTO_TCP
    );
    if(serverSocket == INVALID_SOCKET){
        cout<<"Socket creation failed"<<endl;
        return false;
    }
    cout<<"Socket created successfully"<<endl;
    return true;
}