#pragma once
#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>
#include<string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
class SocketManager{
    private: 
    SOCKET serverSocket;
    string requestPath;
    string username;
    string requestMethod;
    public:
    bool initialize();
    bool createSocket();
    bool bindSocket();
    bool startListening();
    bool acceptClient();
    bool receiveRequest(SOCKET clientSocket);
    void log(const string & message);
    bool sendResponse(SOCKET clientSocket);
    string getContentType(string &filename);
};