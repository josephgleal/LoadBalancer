
#include "classes.h"
using namespace std;


/**
 * request constructor.
 * creates a request with an inIP, outIP and time. The time is the number
 * of clock cycles that the request will take to process.
 */
request::request(/* args */)
{
    ip = generateIP();
    time = generateTime();
    outIP = generateIP();
}

request::~request()
{
}

/**
 * Randomly generates the number of clock cycles that it will take to complete the request. The time will be
 * between 1 and 500
 */
int request::generateTime(){
    int time = rand() % 500 + 1;
    // int time = 1;
    return time;
}

/**
 * Randomly generates an IP address. Used to generate the inbound and outbound IP addresses.
 */
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

/**
 * retrieves the inbound IP address.
 */
string request::getIP(){
    return this->ip;
}

/**
 * retrieves the outbound IP address.
 */
string request::getOutIP(){
    return this->outIP;
}

/**
 * retrieves the time to process the request.
 */
int request::getTime(){
    return time;
}


/**
 * webServer constructor.
 * creates a webServer that has a boolean set to false, and a int counter that is used to keep track of 
 * the time left to finish processing the server's current request
 */
webServer::webServer()
{
    busy = false;
    timeLeft = 0;
}

webServer::~webServer()
{
}

/**
 * assigns a process to the server and sets it's status to busy.
 */
void webServer::setTime(unsigned int n){
    timeLeft = n;
    busy = true;
}

/**
 * decreases the time remaining before the sever is available to process another task.
 */
void webServer::decrementTime(){
    timeLeft = timeLeft - 1;
    if (timeLeft <= 0){
        busy = false;
    }
}

/**
 * constructor for loadBalancer. A private boolean to determine if there are any processes running is set to false upon instantiation.
 */
loadBalancer::loadBalancer(/* args */)
{
    processesRunning = false;
}

loadBalancer::~loadBalancer()
{
}

/**
 * creates a server and adds it to the server list.
 */
void loadBalancer::addServer(){
    servers.push_back(webServer());
}

/**
 * 
 */
// void loadBalancer::removeServer(){

// }

/**
 * instanciates the request queue and server list based on the size of respective parameters r and s
 */
void loadBalancer::startup(int r, int s){
    for(int i = 0; i < r; i++){
        this->addRequest();
    }
    for(int i = 0; i < s; i++){
        this->addServer();
    }
}

/**
 * Randomly generates a new request to place in the request queue
 */
void loadBalancer::simulator(){
    int random = rand() % 100;
    //4% chance of a new request each clock cycle
    if(random > 95 && requestqueue.size() > 0){
        requestqueue.push(request());
        cout<<"request added"<<endl;
    }
    
}

/**
 * creates a new request and adds it to the loadbalancer's request queue
 */
void loadBalancer::addRequest(){
    requestqueue.push(request());
}

/**
 * removes the front request from the request queue
 */
void loadBalancer::popRequest(){
    requestqueue.pop();
}


// /**
//  * 
//  */
// void loadBalancer::printServers(){
//     // for(int i = 0; i < servers.size(); i++){
//     //     cout<<servers.at(i).g
//     // }
// }

/**
 * prints the list of requests in the request queue
 */
void loadBalancer::printRequests(){
    for (size_t i = 0; i < requestqueue.size(); i++)
        {
            cout << requestqueue.front().getIP() << endl;
            requestqueue.push(requestqueue.front());
            requestqueue.pop();
        }
}

/**
 * runs the load balancer. Checks if any severs are avaible to process a request from the request queue.
 * Accepts new requests. Prints output
 */
void loadBalancer::run(unsigned int n){
    unsigned int clock = 0;
    int activeServers = 0;
    bool processAssigned = false;
    int longestBusyPeriod = 0;
    int reportPeriod = 0;
    //while the request queue has requests, or there are servers processing requests
    cout<<"starting request queue size "<<requestqueue.size()<<endl;
    cout<<"every clock cycle there is a 4 percent chance of a request being added so approximately 1 request every 25 seconds."<<endl;
    cout<<"every request has a processing time between 1 and 500"<<endl<<endl;

    while(!requestqueue.empty() || activeServers > 0){
        if(clock >= n){
            break;
        }
        activeServers = 0;
        processAssigned = false;
        for(int i = 0; i < servers.size(); i++){

            //this block prevents a bufferoverflow error caused by assigning pieces of memory that should not
            //be accessable once the queue is empty. Otherwise the for loop would continue to assign request that it should not be able to access
            //this causes the size of the queue to go from 1 to an extremely large number
            if(requestqueue.size() < 1){
                break;
            }
            
            //if server is not busy, assign it a process
            if (!servers.at(i).busy){
                servers.at(i).setTime(requestqueue.front().getTime());
                cout<<"request "<<requestqueue.front().getIP()<<" assigned to " << requestqueue.front().getOutIP()<<endl;
                requestqueue.pop();
                processAssigned = true;
                longestBusyPeriod = 0;
            }
            //if server is busy then decrement the time it has left
            else{
                servers.at(i).decrementTime();
                activeServers++;
                }
            
            
        }
        if(processAssigned == false){
                longestBusyPeriod++;
            }
        if(reportPeriod < longestBusyPeriod){
            reportPeriod = longestBusyPeriod;
        }
        
        // cout<<"requestqueue size "<< requestqueue.size()<<endl;
        simulator();
        clock++;
    }
    cout<<endl;
    if(requestqueue.size() == 0){
        cout<<"queue empty"<<endl;
        cout<<"clock cycles "<< clock<<endl;
        cout<<"longest busy period (all servers are busy): " << reportPeriod <<endl;
    }
    else if(clock >= n){
        cout << "max clock cycles reached at " << n << endl;
        cout<<"longest busy period (all servers are busy): " << reportPeriod << endl;
        cout<<"ending requestqueue size "<< requestqueue.size()<<endl;
    }
    
}
