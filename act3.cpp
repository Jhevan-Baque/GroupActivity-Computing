#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void washDishes() {
    string Steps[4] = {"1. Get the dishes", "2. Fill the sink", "3. Wash the dishes", "4. Rinse"};
    for (int i = 0 ; i < 4; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void foldClothes() {
    string Steps[3] = {"1. Lay the clothes flat", "2. Fold the sides", "3. Fold the top"};
    for (int i = 0 ; i < 3; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void PerformHouseChores() {
    cout << "Performing House Chores (Parallel).." << endl;
    thread t1(washDishes);
    thread t2(foldClothes);

    t1.join();
    t2.join();
}

int main() {
    PerformHouseChores();
    return 0;
}
