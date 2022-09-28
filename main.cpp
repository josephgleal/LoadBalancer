#include <iostream>
#include <string>
#include <random>
using namespace std;

class request{
    public:
        int time = generateTime();
        string ip = generateIP();

        string generateIP(){
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
        int generateTime(){
            int time = rand() % 10 + 1;
            return time;
        }
};


int main(){
    // Get the system time.
    unsigned seed = time(0);
   
   // Seed the random number generator.
    srand(seed);
    request *r = new request();
    cout<<r->ip<<endl;
}