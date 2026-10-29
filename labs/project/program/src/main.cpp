#include <iostream>
#include "Container.h"
using namespace std;

// Displaying information by reading properties of object passed by value
void display(Container c) {
    cout << "--- Container Info (Passed by Value) ---" << endl;
    cout << "Number: " << c.getNumber() << endl;
    cout << "Tare Weight: " << c.getTare() << endl;
    cout << "Max Weight: " << c.getMaxWeight() << endl;
    cout << "Net Weight (Cargo): " << c.getNetWeight() << endl;
    cout << "Gross Weight: " << c.getGrossWeight() << endl;
    cout << "Strength: " << c.getStrength() << "\n" << endl;
}

// Displaying current weight of cargo (passed by reference)
void displayCargo(Container& c) {
    cout << "Current Cargo (Net Weight): " << c.getNetWeight() << endl;
}

// Container handling procedure
void testLoadAndUnload(Container& c, double goods) {
    cout << "--- Testing Load and Unload ---" << endl;
    displayCargo(c);

    cout << "Loading " << goods << " units..." << endl;
    c.loadCargo(goods);
    displayCargo(c);

    cout << "Unloading " << goods << " units..." << endl;
    c.unloadCargo(goods);
    displayCargo(c);
    cout << endl;
}

// Creation of automatic, local object on the stack
void testLocalObject() {
    cout << "=== Testing Local Object ===" << endl;
    Container localC(101);
    localC.setMaxWeight(30000.0);
    localC.setTare(2000.0);
    localC.setStrength(100000.0);

    display(localC);
    testLoadAndUnload(localC, 15000.0);
}

// Creation of dynamic object on the heap
Container* prepare(int number, double goods) {
    Container* dynamicC = new Container(number);
    dynamicC->setMaxWeight(25000.0);
    dynamicC->setTare(2500.0);
    dynamicC->loadCargo(goods);
    return dynamicC;
}

// Displaying information of object passed by pointer
void display(Container* p) {
    if (p != nullptr) {
        cout << "--- Container Info (Passed by Pointer) ---" << endl;
        cout << "Number: " << p->getNumber() << endl;
        cout << "Gross Weight: " << p->getGrossWeight() << endl;
        cout << "Max Cargo Allowed: " << p->getMaxCargo() << "\n" << endl;
    }
}

// Managing dynamic object lifecycle
void testDynamicObject() {
    cout << "=== Testing Dynamic Object ===" << endl;
    Container* myContainer = prepare(202, 10000.0);
    display(myContainer);

    delete myContainer;
    myContainer = nullptr;
    cout << "Dynamic object deleted and memory freed.\n" << endl;
}

int main() {
    testLocalObject();
    testDynamicObject();
    return 0;
}