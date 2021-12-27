// Addition.java
// Read in 2 numbers, and print out its sum.
// Keep asking user for the number as long as both are at least 0.

import java.util.Scanner;

public class Addition {
    private boolean isTest = false;

    private void run() {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt(), num2 = sc.nextInt();
        if (isTest) {
            System.out.println("num1 = " + num1 + ", num2 = " + num2);
        }

        while (num1 >= 0 || num2 >= 0) {
            System.out.println(num1 + num2);
            num1 = sc.nextInt();
            num2 = sc.nextInt();
        }

        sc.close();
    }
    
    public static void main(String[] args){
        Addition obj = new Addition();
        obj.run();
    }
}
