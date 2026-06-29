#pragma once
#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>
#pragma comment(lib, "ws2_32.lib")
class socketManager{
    private: 
    SOCKET SocketManager;
    public:
    bool initialize();
    bool createSocket();
};