#include "Container.h"
#include <iostream>

using namespace std;

// First constructor initializes number to zero[cite: 15]
Container::Container() : number(0), tareWeight(0.0), maxWeight(0.0), strength(0.0), cargo(0.0) {}

// Second constructor stores the passed non-zero number[cite: 15]
Container::Container(int number) : number(number), tareWeight(0.0), maxWeight(0.0), strength(0.0), cargo(0.0) {}

int Container::getNumber() {
    return this->number;
}

double Container::getTare() {
    return this->tareWeight;
}

void Container::setTare(double tareWeight) {
    // Protect against invalidating current cargo state
    if (tareWeight + this->cargo <= this->maxWeight) {
        this->tareWeight = tareWeight;
    } else {
        cout << "Error: New tare weight conflicts with current cargo and max weight." << endl;
    }
}

double Container::getMaxWeight() {
    return this->maxWeight;
}

void Container::setMaxWeight(double maxWeight) {
    // Protect against setting maxWeight lower than current total weight
    if (maxWeight >= this->tareWeight + this->cargo) {
        this->maxWeight = maxWeight;
    } else {
        cout << "Error: New max weight is less than current gross weight." << endl;
    }
}

double Container::getStrength() {
    return this->strength;
}

void Container::setStrength(double strength) {
    this->strength = strength;
}

double Container::getGrossWeight() {
    return this->tareWeight + this->cargo;
}

double Container::getNetWeight() {
    return this->cargo;
}

double Container::getMaxCargo() {
    return this->maxWeight - this->tareWeight;
}

void Container::loadCargo(double amount) {
    if (amount > 0) {
        if (this->cargo + amount <= getMaxCargo()) {
            this->cargo += amount;
        } else {
            cout << "Warning: Cannot overload container. Loading only up to maximum capacity." << endl;
            this->cargo = getMaxCargo(); 
        }
    }
}

void Container::unloadCargo(double amount) {
    if (amount > 0) {
        if (this->cargo - amount >= 0) {
            this->cargo -= amount;
        } else {
            cout << "Warning: Cannot unload more than current cargo. Emptying container completely." << endl;
            this->cargo = 0.0; 
        }
    }
}