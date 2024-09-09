import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class CarUnitTests {

    private Car car;

    @BeforeEach
    public void setUp() {
        // Create a Car object before each test
        car = new Car("Toyota", "Corolla", 2020, 15.0);  // 15 gallons fuel capacity
    }

    @Test
    public void testInitialFuelLevel() {
        assertEquals(0, car.getFuelLevel(), "Initial fuel level should be 0.");
    }

    @Test
    public void testRefuel() {
        car.refuel(10);
        assertEquals(10, car.getFuelLevel(), 0.01, "Fuel level should be 10 after refueling 10 gallons.");
    }

    @Test
    public void testRefuelBeyondCapacity() {
        car.refuel(20);  // Attempt to refuel more than the fuel tank capacity
        assertEquals(15, car.getFuelLevel(), 0.01, "Fuel level should not exceed the fuel capacity of 15 gallons.");
    }

    @Test
    public void testDrive() {
        car.refuel(10);
        car.drive(100);  // Driving 100 miles, which consumes 5 gallons
        assertEquals(5, car.getFuelLevel(), 0.01, "Fuel level should be 5 after driving 100 miles.");
    }

    @Test
    public void testDriveWithoutEnoughFuel() {
        car.refuel(2);
        Exception exception = assertThrows(IllegalStateException.class, () -> car.drive(100));
        assertEquals("Not enough fuel to drive the distance.", exception.getMessage());
    }

    @Test
    public void testIsEmpty() {
        assertTrue(car.isEmpty(), "The car should be empty initially.");
        car.refuel(5);
        assertFalse(car.isEmpty(), "The car should not be empty after refueling.");
    }

    @Test
    public void testNegativeRefuel() {
        Exception exception = assertThrows(IllegalArgumentException.class, () -> car.refuel(-5));
        assertEquals("Fuel amount cannot be negative.", exception.getMessage());
    }
}
