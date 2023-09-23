// Addition.java
// Read in 2 numbers using for big inters, and print out its sum.
// Keep asking user for the number as long as both are at least 0.

import java.math.BigInteger;
import java.util.Scanner;

public class Addition {
    private boolean isTest = false;

    private void run() {
        Scanner sc = new Scanner(System.in);
        BigInteger firstNumber = sc.nextBigInteger();
        BigInteger secondNumber = sc.nextBigInteger();

        if (isTest) {
            System.out.println("firstNumber = " + firstNumber + ", secondNumber = " + secondNumber);
        }

        while (firstNumber.intValue() >= 0 || secondNumber.intValue() >= 0) {
            System.out.println(firstNumber.add(secondNumber));
            firstNumber = sc.nextBigInteger();
            secondNumber = sc.nextBigInteger();
        }

        sc.close();
    }
    
    public static void main(String[] args){
        Addition obj = new Addition();
        obj.run();
    }
}
