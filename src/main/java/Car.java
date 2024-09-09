public class Car {
    private String make;
    private String model;
    private int year;
    private double fuelCapacity;
    private double fuelLevel;
    private double mileage;
    private double fuelEfficiency;
    private boolean isEngineOn;

    public Car(String make, String model, int year, double fuelCapacity, double fuelEfficiency) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.fuelCapacity = fuelCapacity;
        this.fuelLevel = 0;  // Car starts with an empty tank
        this.mileage = 0;    // Initial mileage is zero
        this.fuelEfficiency = fuelEfficiency;  // Set fuel efficiency (e.g., 20 miles per gallon)
        this.isEngineOn = false;  // Engine starts off
    }

    public void startEngine() {
        this.isEngineOn = true;
    }

    public void stopEngine() {
        this.isEngineOn = false;
    }

    public void refuel(double amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("Fuel amount cannot be negative.");
        }
        this.fuelLevel = Math.min(this.fuelLevel + amount, this.fuelCapacity);
    }

    public void drive(double distance) {
        if (!isEngineOn) {
            throw new IllegalStateException("Engine is off. Cannot drive.");
        }
        double fuelNeeded = distance / this.fuelEfficiency;
        if (fuelNeeded > this.fuelLevel) {
            throw new IllegalStateException("Not enough fuel.");
        }
        this.mileage += distance;
        this.fuelLevel -= fuelNeeded;
    }

    public boolean isEmpty() {
        return this.fuelLevel == 0;
    }

    public double getRemainingRange() {
        return this.fuelLevel * this.fuelEfficiency;
    }

    public boolean needsMaintenance() {
        return this.mileage > 10000;  // Example condition for maintenance
    }

}