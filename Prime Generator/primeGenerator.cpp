#include <iostream>
#include <atomic>
#include <thread>
#include <string>
#include <cmath>
using namespace std;

atomic<bool> running(true);


bool isPrime(int n){
    if(n > 2 && n % 2 == 0) return false;
    if(n > 3 && n % 2 == 0) return false;
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n % i == 0) return false;
    }
    return true;
}



void prime(){
    int n = 2;
    while(running){
        if(isPrime(n)){
            cout << n << " ";
        }
        n++;
    }
}

void stopCmd(){
    string cmd;
    while(true){
        getline(cin, cmd);
        if(cmd == "stop"){
            running = false;
            break;
        }
    }
}



int main(){
    thread t1(prime);
    thread t2(stopCmd);

    t1.join();
    t2.join();

    cout << endl << "Prime Stopped";
    return 0;
}