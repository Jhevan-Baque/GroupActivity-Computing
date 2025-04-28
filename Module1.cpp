#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Activity 1 (Sequential)

void makeSandwich() {
    string Steps[5] = {"1. Get Bread", "2. Add Cheese", "3. Add Ham", "4. Assemble Sandiwch"};
    for (int i = 0 ; i < 4; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// Activity 2 (Concurrent)

void prepareCoffeeAndToast() {
    cout << "Preparing Coffee and Toast (Concurrent):" << endl;
    string CoffeeSteps[4] = {"1. Grinding  coffee", "2. Heating water", "5: Brewing coffee"};
    string ToastSteps[4] = {"1. Placing toast in toaster", "2. Selecting temperature ", "3. Toasting Bread", ""};
    int i = 0;
    bool con = true;
    while (i != 3) {
        if (con == true) {
            con = false;
            cout << CoffeeSteps[i] << endl;
        }else {
            con = true;
            cout << ToastSteps[i] << endl;
            i++;
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }

}

// Activity 3 (Parallel)

void washDishes() {
    string Steps[5] = {"1. Get the dishes", "2. Fill the sink", "3. Wash the dishes", "4. Rinse"};
    for (int i = 0 ; i < 4; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void foldClothes() {
    string Steps[4] = {"1. Lay the clothe Flat", "2. Fold the Sides", "3. Fold the Top"};
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

// Activity 4 (Concurrent and Parallel)

void decorateVenue() {
    cout << "Decorating venue.." << endl;
}

void prepareFood() {
    cout << "Preparing food (Concurrent):" << endl;
}

void organizeGames() {
    cout << "Organizing games.." << endl;
}

void organizeParty() {
    cout << "Organizing party.." << endl;

    thread decorationThread(decorateVenue);
    thread food_thread(prepareFood);
    thread games_thread(organizeGames);

    decorationThread.join();
    food_thread.join();
    games_thread.join();

}




int main() {
    int choice;
    do {
        cout << "\nSelect an activity:" << endl;
        cout << "1. Make a Sandwich (Sequential)" << endl;
        cout << "2. Prepare Coffee and Toast (Concurrent)" << endl;
        cout << "3. Perform House Chores (Parallel)" << endl;
        cout << "4. Organize a Party (Concurrent and Parallel)" << endl;
        cout << "5. Exit" << endl;
        cout << ": ";
        cin >> choice;

        switch (choice) {
            case 1:
                makeSandwich();
                break;
            case 2:
                prepareCoffeeAndToast();
                break;
            case 3:
                PerformHouseChores();
                break;
            case 4:
                organizeParty();
                break;
            case 5:
                cout << "Exiting..";
                break;
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
