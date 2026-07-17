#include"../include/router.h"
using namespace std;
std::string router :: getFilePath(const std::string& requestPath){
    if(requestPath=="/"){
        return "public/index.html";
    }
    return "public"+requestPath;
}