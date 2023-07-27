import java.lang.Math;
import java.text.DecimalFormat;
import java.util.Scanner;

class FreezerV2 {

    private boolean isTest = false;
    
    // Computes value of small t
    // Precon: User has not entered values of hours and minutes
    // Postcon: Compute temperature
    private double computesSmallT() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter hours and minutes since power failure: ");
        double hours = sc.nextDouble();
        double minutes = sc.nextDouble();
        sc.close();

        minutes /= 60; // Convert minutes in terms of hours
        if (isTest) {
            System.out.println("hours = " + hours + ", minutes = " + minutes);
        }
        return (hours + minutes);
    }

    // Computes temperature
    // Precon: smallT has been calculated
    // Postcon: Displays temperature
    private double computesTemperature(double smallT) {
        double numerator = (4.0 * Math.pow(smallT, 10.0));
        double denominator = (2.0 + Math.pow(smallT, 9.0));

        return ((numerator / denominator) - 20.0);
    }

    // Displays temperature
    // Precon: temperature has been calculated
    // Postcon: Nil
    private void displaysTemperature(double temperature) {
        DecimalFormat df = new DecimalFormat("0.00");
        System.out.println("Temperature in freezer = " + df.format(temperature));
    }

    private void run() {
        double smallT = computesSmallT();
        double temperature = computesTemperature(smallT);
        displaysTemperature(temperature);
    }
    
    public static void main(String[] args) {
        FreezerV2 obj = new FreezerV2();
        obj.run();
    }
}
