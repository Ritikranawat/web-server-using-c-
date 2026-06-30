using namespace std;
# include "../include/socket_manager.h"
bool SocketManager :: initialize(){
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2,2),&wsaData);
    if(result !=0){
        cout<<"WSASTARTUP failed\n";
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
bool SocketManager :: bindSocket(){
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(bind(serverSocket,(sockaddr*)&serverAddress,sizeof(serverAddress)) == SOCKET_ERROR){
        cout<<"Bind failed"<<endl;
        return false;
    }
    cout<<"Bind successfully"<<endl;
    return true;
}
bool SocketManager :: startListening(){
    if(listen(serverSocket,SOMAXCONN)==SOCKET_ERROR){
        cout<<"Listen failed"<<endl;
        return false;
    }
    cout<<"server is listening"<<endl;
    return true;
}