#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Activity 1 (Sequential)

void makeSandwich() {
    string Steps[4] = {"1. Get Bread", "2. Add Cheese", "3. Add Ham", "4. Assemble Sandiwch"};
    for (int i = 0 ; i < 4; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// Activity 2 (Concurrent)

void prepareCoffeeAndToast() {
    cout << "Preparing Coffee and Toast (Concurrent):" << endl;
    string CoffeeSteps[3] = {"1. Grinding  coffee", "2. Heating water", "3: Brewing coffee"};
    string ToastSteps[3] = {"1. Placing toast in toaster", "2. Selecting temperature ", "3. Toasting Bread"};
    
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
    string Steps[4] = {"1. Get the dishes", "2. Fill the sink", "3. Wash the dishes", "4. Rinse"};
    for (int i = 0 ; i < 4; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void foldClothes() {
    string Steps[3] = {"1. Lay the clothes Flat", "2. Fold the Sides", "3. Fold the Top"};
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
    string Steps[3] = {"1. Hanging decorations", "2. Setting up tables", "3. Placing centerpieces"};
    for (int i = 0; i < 3; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void prepareFood() {
    cout << "Preparing Food (Concurrent - Alternating steps):" << endl;
    string CookingSteps[3] = {"1. Cooking main dish", "2. Preparing appetizers", "3. Making desserts"};
    string PlatingSteps[3] = {"1. Setting plates", "2. Garnishing dishes", "3. Arranging on tables"};

    int i = 0;
    bool isCookingTurn = true;

    while (i < 3) {
        if (isCookingTurn) {
            cout << CookingSteps[i] << endl;
            isCookingTurn = false;
        } else {
            cout << PlatingSteps[i] << endl;
            isCookingTurn = true;
            i++;
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void organizeGames() {
    string Steps[3] = {"1. Setting up games area", "2. Preparing game materials", "3. Briefing participants"};
    for (int i = 0; i < 3; i++) {
        cout << Steps[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void organizeParty() {
    cout << "Organizing Party (Concurrent + Parallel):" << endl;

    thread t1(decorateVenue);
    thread t2(prepareFood);
    thread t3(organizeGames);

    t1.join();
    t2.join();
    t3.join();
}

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

// Option 5
void packingMenu() {
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
}


// Main menu
int main() {
    int choice;
    do {
        cout << "\nSelect an activity:" << endl;
        cout << "1. Make a Sandwich (Sequential)" << endl;
        cout << "2. Prepare Coffee and Toast (Concurrent)" << endl;
        cout << "3. Perform House Chores (Parallel)" << endl;
        cout << "4. Organize a Party (Concurrent and Parallel)" << endl;
        cout << "5. Packing Boxes (Sequential or Parallel)" << endl;
        cout << "6. Exit" << endl;
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
                packingMenu();
                break;
            case 6:
                cout << "\nExiting..." << endl;
                break;
            default:
                cout << "\nInvalid Choice!" << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
