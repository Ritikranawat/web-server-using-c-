#include"../include/middleware.h"
#include<iostream>
void middleware::logRequest(const std:: string& method,const std::string&path){
    std::cout<<"[REQUEST]"<<method<<" "<<path<<std::endl;
}