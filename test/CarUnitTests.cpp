// Copyright 2024 Shivam Chaturvedi
#include <gtest/gtest.h>
#include "Car.h"

class CarUnitTests : public ::testing::Test {
 protected:
    Car car;

    void SetUp() override {
        // 50 gallon capacity, 20 mpg efficiency
        car = Car("Toyota", "Corolla", 2024, 50.0, 20.0);
    }
};

TEST_F(CarUnitTests, TestInitialFuelLevel) {
    EXPECT_EQ(0, car.getRemainingRange());
}

TEST_F(CarUnitTests, TestRefuel) {
    car.refuel(10);
    // 10 gallons * 20 mpg = 200 miles
    EXPECT_EQ(200, car.getRemainingRange());
}

TEST_F(CarUnitTests, TestRefuelBeyondCapacity) {
    // Capacity is 50
    car.refuel(60);
    // 50 gallons * 20 mpg = 1000 miles
    EXPECT_EQ(1000, car.getRemainingRange());
}

TEST_F(CarUnitTests, TestDrive) {
    car.refuel(20);
    car.startEngine();
    car.drive(100);
    // (20 - 5) gallons * 20 mpg = 300 miles
    EXPECT_EQ(300, car.getRemainingRange());
}

TEST_F(CarUnitTests, TestDriveWithoutEnoughFuel) {
    car.refuel(1);
    car.startEngine();
    EXPECT_THROW(car.drive(30), std::logic_error);
}

TEST_F(CarUnitTests, TestIsEmpty) {
    EXPECT_TRUE(car.isEmpty());
    car.refuel(1);
    EXPECT_FALSE(car.isEmpty());
}

TEST_F(CarUnitTests, TestNegativeRefuel) {
    EXPECT_THROW(car.refuel(-5), std::invalid_argument);
}

TEST_F(CarUnitTests, TestDriveWithEngineOff) {
    car.refuel(20);
    EXPECT_THROW(car.drive(100), std::logic_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
