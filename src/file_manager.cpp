#include"../include/file_manager.h"
#include<fstream>
#include<sstream>
using namespace std;
bool fileManager :: readFile(const string & filename , string & body){
    ifstream file(filename,ios :: binary);
    if(!file.is_open()) {
        return false;
    }
    stringstream ss;
    ss<<file.rdbuf();
    body = ss.str();
    return true;
}