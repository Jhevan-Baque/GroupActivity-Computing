#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void prepareCoffeeAndToast() {
    cout << "Preparing Coffee and Toast (Concurrent):" << endl;
    string CoffeeSteps[3] = {"1. Grinding coffee", "2. Heating water", "3: Brewing coffee"};
    string ToastSteps[3] = {"1. Placing toast in toaster", "2. Selecting temperature", "3. Toasting Bread"};
    
    int i = 0;
    bool con = true;
    
    while (i != 3) {
        if (con == true) {
            con = false;
            cout << CoffeeSteps[i] << endl;
        } else {
            con = true;
            cout << ToastSteps[i] << endl;
            i++;
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main() {
    prepareCoffeeAndToast();
    return 0;
}
