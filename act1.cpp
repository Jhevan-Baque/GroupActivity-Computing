#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void makeSandwich() {
    string Steps[4] = {"1. Get Bread", "2. Add Cheese", "3. Add Ham", "4. Assemble Sandwich"};
    for (int i = 0 ; i < 4; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main() {
    makeSandwich();
    return 0;
}
