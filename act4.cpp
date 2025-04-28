#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void decorateVenue() {
    string Steps[3] = {"1. Hanging decorations", "2. Setting up tables", "3. Placing centerpieces"};
    for (int i = 0; i < 3; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void prepareFoodCooking() {
    string CookingSteps[3] = {"1. Cooking main dish", "2. Preparing appetizers", "3. Making desserts"};
    for (int i = 0; i < 3; i++) {
        cout << CookingSteps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void checkProgress() {
    string decorationProgress[3] = {"1. Checking progress on decorations", "2. Checking progress on tables", "3. Checking progress on centerpieces"};
    string foodProgress[3] = {"1. Checking progress on food preparation", "2. Checking progress on main dishes", "3. Checking progress on desserts"};

    int i = 0;
    bool isDecorationTurn = true;

    while (i < 3) {
        if (isDecorationTurn) {
            cout << decorationProgress[i] << endl;
            isDecorationTurn = false; 
        } else {
            cout << foodProgress[i] << endl;
            isDecorationTurn = true; 
            i++;
        }
        this_thread::sleep_for(chrono::milliseconds(500)); 
    }
}

void organizeParty() {
    cout << "Organizing Party (Concurrent + Parallel):" << endl;

    thread t1(decorateVenue); // Parallel
    thread t2(prepareFoodCooking);  // Parallel
    thread t3(checkProgress); // Concurrent
    
    t1.join();
    t2.join();
    t3.join();
}

int main() {
    organizeParty();
    return 0;
}
