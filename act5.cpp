#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void packBoxSequential() {
    cout << "\nPacking boxes sequentially...\n" << endl;
    for (int i = 1; i <= 3; ++i) {
        cout << "Packing Box " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Box " << i << " packed!" << endl;
    }
    cout << "\nAll boxes packed (Sequential)." << endl;
}

void packBox(string boxName) {
    cout << "Packing " << boxName << "..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << boxName << " packed!" << endl;
}

void packBoxParallel() {
    cout << "\n Packing boxes in parallel...\n" << endl;
    thread t1(packBox, "Box 1");
    thread t2(packBox, "Box 2");
    thread t3(packBox, "Box 3");

    t1.join();
    t2.join();
    t3.join();
}

int main() {
    int subChoice;
    cout << "\nChoose Packing Method:" << endl;
    cout << "1. Sequential Packing" << endl;
    cout << "2. Parallel Packing" << endl;
    cout << ": ";
    cin >> subChoice;

    if (subChoice == 1) {
        packBoxSequential();
    } else if (subChoice == 2) {
        packBoxParallel();
    } else {
        cout << "\nInvalid Choice!" << endl;
    }
    return 0;
}
