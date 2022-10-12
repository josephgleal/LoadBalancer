
#include "classes.h"
using namespace std;



request::request(/* args */)
{
    ip = generateIP();
    time = generateTime();
}

request::~request()
{
}


int request::generateTime(){
    int time = rand() % 10 + 1;
    return time;
}

string request::generateIP(){
    int random = rand() % 100 + 155;
    string first = to_string(random);
    random = rand() % 100 + 155;
    string second = to_string(random);
    random = rand() % 100 + 155;
    string third = to_string(random);
    random = rand() % 100 + 155;
    string fourth = to_string(random);

    return first + "." + second + "." + third + "." + fourth;
}

string request::getIP(){
    return this->ip;
}



webServer::webServer()
{
}

webServer::~webServer()
{
}


loadBalancer::loadBalancer(/* args */)
{
}

loadBalancer::~loadBalancer()
{
}

void loadBalancer::addServer(webServer s){
    servers.push_back(s);
}

void loadBalancer::removeServer(webServer s){

}


void loadBalancer::simulator(){}
void loadBalancer::addRequest(){}
void loadBalancer::popRequest(){}