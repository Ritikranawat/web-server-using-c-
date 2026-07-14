#include<fstream>
#include<sstream>
# include "../include/socket_manager.h"
using namespace std;
string SocketManager:: getContentType(string & filename){
    if(filename.size()>=5 && filename.substr(filename.size()-5)==".html") return "text/html";
    if(filename.size()>=4 && filename.substr(filename.size()-4)==".css") return "text/css";
    if(filename.size()>=3 && filename.substr(filename.size()-3)==".js") return "application/javascript";
    if(filename.size()>=4 && filename.substr(filename.size()-4)==".png") return "image/png";
    if(filename.size()>=4 && filename.substr(filename.size()-4)==".jpg") return "image/jpeg";
    if(filename.size()>=5 && filename.substr(filename.size()-5)==".jpeg") return "image/jpeg";
    return "application/octet-stream";
}
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
bool SocketManager :: acceptClient(){
    SOCKET clientSocket;
    sockaddr_in clientAddress;
    int clientSize = sizeof(clientAddress);
    clientSocket = accept(serverSocket , (sockaddr*)&clientAddress,&clientSize);
    if(clientSocket == INVALID_SOCKET){
        cout<<"Accept failed"<<endl;
        return false;
    }
    cout<<"Client accepted successfully "<<endl;
    receiveRequest(clientSocket);
    sendResponse(clientSocket);
    shutdown(clientSocket , SD_SEND);
    closesocket(clientSocket);
    return true;
}
bool SocketManager :: receiveRequest(SOCKET clientSocket){
    char buffer[4096];
    int bytesReceived = recv(clientSocket,buffer,sizeof(buffer)-1,0);
    if(bytesReceived == SOCKET_ERROR){
        cout<<"Receive failed"<<endl;
        return false;
    }
    buffer[bytesReceived] = '\0';
    string request(buffer);
    cout<<"reached parser"<<endl;
    size_t lineEnd = request.find("\r\n");
    string requestLine = request.substr(0,lineEnd);
    istringstream iss(requestLine);
    string method , path,version;
    iss>>method>>path>>version;
    cout<<"path :  "<<path<<endl;
    requestPath = path;
    cout<< "HTTP Request :\n";
    cout<<buffer<<endl;
    return true;
}
bool SocketManager :: sendResponse(SOCKET clientSocket){
    string filename;
    if(requestPath=="/"){
        filename = "public/index.html";
    }
    else if (requestPath=="/about"){
        filename = "public/about.html";
    }
    else if (requestPath == "/style.css"){
        filename = "public/style.css";
    }
    else{
        filename = "public/404.html";
    }
    cout<<"opening "<<filename;
    ifstream file(filename);
    if(!file){
        cerr<<"could not open index.html\n";
        return false;
    }
    string contentType = getContentType(filename);
    stringstream ss;
    ss << file.rdbuf();
    string body = ss.str();
    string response ="HTTP/1.1 200 OK\r\n";
    response+="Content-type: "+contentType+" \r\n";
    response+="Content-length: " + to_string(body.length()) + "\r\n";
    response+= "Connection: close\r\n";
    response+= "\r\n";
    response+=body;
    cout<<response<<endl;
    int result = send(clientSocket,response.c_str(),response.length(),0);
    cout<<"bytes sent "<<result<<endl;
    return true;
}