import java.text.DecimalFormat;
import java.util.Scanner;
class Freezer {

    private boolean isTest = false;

    // Computes value of small t as part of formula
    // Precon: User has not entered values of hours and minutes
    // Postcon: Values that user entered has been correctly assigned to hours and minutes
    private double computesSmallT() {
        Scanner sc = new Scanner(System.in);
    
        System.out.print("Enter hours and minutes since power failure: ");
        double hours = sc.nextDouble();
        double minutes = sc.nextDouble(); 
        sc.close();
        
        minutes /= 60; // minutes is assigned value in terms of hours.

        return (hours + minutes);
    }

    // Computes temperature
    // Precon: User has entered values of hours and minutes
    // Postcon: Temperature has been computed and
    private double computesTemperature(double smallT) {
        return ((4.0 * smallT * smallT) / (smallT + 2.0)) - 20.0;
    }

    // Displays temperature
    // Precon: computesTemperature has been computed
    // Postcon: Nil
    private void displaysTemperature(double T) {
        DecimalFormat df = new DecimalFormat("0.00");
        System.out.println("Temperature in freezer = " + df.format(T));
    }

    private void run() {
        double smallT = computesSmallT();
        double T = computesTemperature(smallT);
        displaysTemperature(T);
    }

    public static void main(String[] args) {
        Freezer obj = new Freezer();
        obj.run();
    }
}
