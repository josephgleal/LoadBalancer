#ifndef CLASSES_H
#define CLASSES_H
#include <queue>
#include <string>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

    /** 
     * A request.
     * More detailed request description.
     */
class request
{
private:
    /* data */
    int time;
    string ip;
    string outIP;
public:
    request(/* args */);
    ~request();
    int generateTime();
    string generateIP();

    string getIP();
    string getOutIP();
    int getTime();
};

class webServer
{
private:
    /* data */
public:
    webServer();
    ~webServer();

    /**
    * True if the server has a process assigned to it. False otherwise.
    */
    bool busy;
    /**
    * Keeps track of the time left before the server finished processing the request. Once it reaches 0 then 
    * "busy" will be set to false.
    */
    unsigned int timeLeft;
    void setTime(unsigned int n);
    void decrementTime();
};

class loadBalancer
{
private:
    vector<webServer> servers;
    queue<request> requestqueue;
public:
    loadBalancer(/* args */);
    ~loadBalancer();
    void addServer();
    // void removeServer();
    void simulator();
    void addRequest();
    void popRequest();
    void startup(int r, int s);
    // void printServers();
    void printRequests();
    void run(unsigned int n);

    /** True if there are any processes running. False if no servers have processes assigned to them.
     * Used to ensure that all processes finish running after the request queue is empty.
    */
    bool processesRunning; 
    
};













// class request{
//     public:
//         int time = generateTime();
//         string ip = generateIP();

//         string generateIP(){
//             int random = rand() % 100 + 155;
//             string first = to_string(random);
//             random = rand() % 100 + 155;
//             string second = to_string(random);
//             random = rand() % 100 + 155;
//             string third = to_string(random);
//             random = rand() % 100 + 155;
//             string fourth = to_string(random);

//             return first + "." + second + "." + third + "." + fourth;
//         }
//         int generateTime(){
//             int time = rand() % 10 + 1;
//             return time;
//         }
// };

#endif