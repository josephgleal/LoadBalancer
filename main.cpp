#include <iostream>
#include <string>
#include <random>
#include "classes.h"
#include <memory>

using namespace std;



int main(){
    // Get the system time.
    unsigned seed = time(0);
   
   // Seed the random number generator.
    srand(seed);
    // request *r = new request();
    // cout<<r->getIP()<<endl;

    int serverNumber = 0;
    cout<<"server number?"<<endl;
    cin >> serverNumber;
    int requestNumber = 100000;
    // webServer s;
    loadBalancer l;
    //not proper use of serverNumber
    // for(int i = 0; i < requestNumber; i++){
    //     l.addRequest();
    // }
    // l.printRequests();
    l.startup(requestNumber,serverNumber);
    l.run();
}