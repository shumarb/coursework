// Addition.java
// Read in 2 numbers, and print out its sum.
// Keep asking user for the number as long as both are at least 0.

import java.util.*;
import java.io.*;

public class Addition{
    private Scanner sc = new Scanner(System.in);
    private boolean test = false;

    public static void main(String[] args){
        Addition obj = new Addition();
        obj.run();
    }

    private void run(){
        int num1, num2;
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        if( test ){
            System.out.println("num1 = " + num1 + ", num2 = " + num2);
        }

        while( num1>=0 || num2>=0 ){
            int sum = num1+num2;
            System.out.println(sum);
            num1 = sc.nextInt();
            num2 = sc.nextInt();
        }
    }
}
