// AdditionA.java
// Read in 2 numbers, and print out its sum.
// Keep asking user for the number as long as both are at least 0.

import java.util.Scanner;

public class Addition {
    private boolean isTest = false;

    private void run() {
        Scanner sc = new Scanner(System.in);
        int firstNumber = sc.nextInt();
        int secondNumber = sc.nextInt();
        if (isTest) {
            System.out.println("firstNumber = " + firstNumber + ", secondNumber = " + secondNumber);
        }

        while (firstNumber >= 0 || secondNumber >= 0) {
            System.out.println((firstNumber + secondNumber));
            firstNumber = sc.nextInt();
            secondNumber = sc.nextInt();
        }

        sc.close();
    }
    
    public static void main(String[] args){
        Addition obj = new Addition();
        obj.run();
    }
}
