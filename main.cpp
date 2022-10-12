#include <iostream>
#include <string>
#include <random>
#include "classes.h"

using namespace std;



int main(){
    // Get the system time.
    unsigned seed = time(0);
   
   // Seed the random number generator.
    srand(seed);
    request *r = new request();
    cout<<r->getIP()<<endl;

    int serverNumber = 0;
    cout<<"server number?"<<endl;
    cin >> serverNumber;
}