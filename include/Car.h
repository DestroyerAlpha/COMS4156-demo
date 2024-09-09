#ifndef INCLUDE_CAR_H_
#define INCLUDE_CAR_H_
// Copyright 2024 Shivam Chaturvedi
#include <string>
class Car {
 public:
        Car(std::string make, std::string model, int year, double fuelCapacity,
         double fuelEfficiency);

        Car();

        void startEngine();
        void stopEngine();
        void refuel(double amount);
        void drive(double distance);
        bool isEmpty();
        double getRemainingRange();
        bool needsMaintenance();
 private:
        std::string make;
        std::string model;
        int year;
        double fuelCapacity;
        double fuelLevel;
        double mileage;
        double fuelEfficiency;
        bool isEngineOn;
};
#endif  // INCLUDE_CAR_H_
