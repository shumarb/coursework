// Addition.java
// Read in 2 numbers, and print out its sum.
// Keep asking user for the number as long as both are at least 0.

import java.math.BigInteger;
import java.util.Scanner;

class Addition {
    private void run() {
        Scanner sc = new Scanner(System.in);

        BigInteger A = sc.nextBigInteger(), B = sc.nextBigInteger();

        while (A.signum() != -1 && B.signum() != -1)
        {
            BigInteger sum = A.add(B);
            System.out.println(sum);
            A = sc.nextBigInteger();
            B = sc.nextBigInteger();
        }

        sc.close();
    }

    public static void main(String[] args) {
        Addition obj = new Addition();
        obj.run();
    }
}
