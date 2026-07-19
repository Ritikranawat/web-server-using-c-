#pragma once
#include<string>
class middleware{
    public:
    static void logRequest (const std:: string& method,const std::string&path);
};