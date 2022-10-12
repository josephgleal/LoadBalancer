#ifndef CLASSES_H
#define CLASSES_H
#include <queue>
#include <string>
#include <random>
#include <vector>
using namespace std;


class request
{
private:
    /* data */
    int time;
    string ip;
public:
    request(/* args */);
    ~request();
    int generateTime();
    string generateIP();

    string getIP();
};

class webServer
{
private:
    /* data */
    queue<request> requestqueue;
public:
    webServer();
    ~webServer();
};

class loadBalancer
{
private:
    vector<webServer> servers;
    queue<request> requestqueue;
public:
    loadBalancer(/* args */);
    ~loadBalancer();
    void addServer(webServer s);
    void removeServer(webServer s);
    void simulator();
    void addRequest();
    void popRequest();
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