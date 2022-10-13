
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
    // int time = 1;
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

int request::getTime(){
    return time;
}



webServer::webServer()
{
    busy = false;
    timeLeft = 0;
}

webServer::~webServer()
{
}

//assigns a process to the server and sets it's status to busy
void webServer::setTime(unsigned int n){
    timeLeft = n;
    busy = true;
}
//decreases the time remaining before the sever is available to process another task
void webServer::decrementTime(){
    timeLeft = timeLeft - 1;
    if (timeLeft <= 0){
        busy = false;
    }
}

//add a request to the webserver's requestqueue
// void webServer::addRequest(){
    
// }
// void webServer::popRequest(){}

// void webServer::printRequests(){
    
// }

//constructor for loadBalancer
loadBalancer::loadBalancer(/* args */)
{
}

loadBalancer::~loadBalancer()
{
}

void loadBalancer::addServer(){
    servers.push_back(webServer());
}

void loadBalancer::removeServer(){

}

void loadBalancer::startup(int r, int s){
    for(int i = 0; i < r; i++){
        this->addRequest();
    }
    for(int i = 0; i < s; i++){
        this->addServer();
    }
    
    
}
void loadBalancer::simulator(){
    int random = rand() % 100;
    if(random > 70){
        requestqueue.push(request());
        cout<<"request added"<<endl;
    }
    
}
void loadBalancer::addRequest(){
    requestqueue.push(request());
}
void loadBalancer::popRequest(){}
// void loadBalancer::startup(){
//     for (int i = 0; i < n; i++){
//         servers.push_back(webServer());
//     }
// }

void loadBalancer::printServers(){
    // for(int i = 0; i < servers.size(); i++){
    //     cout<<servers.at(i).g
    // }
}

void loadBalancer::printRequests(){
    for (size_t i = 0; i < requestqueue.size(); i++)
        {
            cout << requestqueue.front().getIP() << endl;
            requestqueue.push(requestqueue.front());
            requestqueue.pop();
        }
}

void loadBalancer::run(){
    unsigned int clock = 0;
    while(!requestqueue.empty()){
        for(int i = 0; i < servers.size(); i++){

            //this block prevents a bufferoverflow error caused by assigning pieces of memory that should not
            //be accessable once the queue is empty. Otherwise the for loop would continue to assign request that it should not be able to access
            //this causes the size of the queue to go from 1 to an extremely large number
            if(requestqueue.size() < 1){
                break;
            }
            //if server is not busy
            if (!servers.at(i).busy){
                servers.at(i).setTime(requestqueue.front().getTime());
                cout<<"request "<<requestqueue.front().getIP()<<" assigned"<<endl;
                requestqueue.pop();
            }
            //if server is busy then decrement the time it has left
            else{
                servers.at(i).decrementTime();
                }
        }
        cout<<"requestqueue size "<< requestqueue.size()<<endl;
        simulator();
        clock++;
    }
    cout<<"queue empty"<<endl;
    cout<<"clock cycles "<< clock<<endl;
}
