// Copyright 2024 Shivam Chaturvedi
#include "Car.h"
#include <string>
#include <algorithm>
#include <stdexcept>


Car::Car(std::string make, std::string model, int year, double fuelCapacity,
        double fuelEfficiency) : make(make), model(model),
        year(year), fuelCapacity(fuelCapacity), fuelEfficiency(fuelEfficiency),
        fuelLevel(0), mileage(0), isEngineOn(false) {}

Car::Car() {}

void Car::startEngine() {
    this->isEngineOn = true;
}

void Car::stopEngine() {
    this->isEngineOn = false;
}

void Car::refuel(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Fuel amount cannot be negative.");
        }
        this->fuelLevel = std::min(this->fuelLevel + amount,
        this->fuelCapacity);
}

void Car::drive(double distance) {
    if (!this->isEngineOn) {
            throw std::logic_error("Engine is off. Cannot drive.");
        }
        double fuelNeeded = distance / this->fuelEfficiency;
        if (fuelNeeded > this->fuelLevel) {
            throw std::logic_error("Not enough fuel.");
        }
        this->mileage += distance;
        this->fuelLevel -= fuelNeeded;
}
bool Car::isEmpty() {
    return this->fuelLevel == 0;
}

double Car::getRemainingRange() {
    return this->fuelLevel * this->fuelEfficiency;
}

bool Car::needsMaintenance() {
    return this->mileage > 10000;  // Example condition for maintenance
}
