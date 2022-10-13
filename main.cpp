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
    

    int serverNumber = 0;
    cout<<"server number?"<<endl;
    cin >> serverNumber;

    unsigned int maxCycles = 0;
    cout<<"max number of clock cycles?"<<endl;
    cin >> maxCycles;

    // int requestNumber = 10000;
    int requestNumber = serverNumber * 2;
    
    loadBalancer l;
    
    l.startup(requestNumber,serverNumber);
    l.run(maxCycles);
}