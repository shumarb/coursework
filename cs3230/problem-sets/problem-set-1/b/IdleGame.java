import java.util.*;

class IdleGame {

    private boolean isTest = false;

    private int calculateMinimum(int maxLevel, int amountRequired, int[] values, int[] costs) {
        // Memo table states minimum number of taps needed from 0 to max level for
        // current amount
        int[][] memoTable = new int[values[maxLevel] + 1][maxLevel + 1];
        return helper(0, maxLevel, 0, amountRequired, memoTable, values, costs);
    }

    private int helper(int currLevel, int maxLevel, int currAmt, int amountRequired, int[][] memo, int[] values,
            int[] costs) {
        int ans;
        // If current amount >= amount required, no more taps needed
        if (currAmt >= amountRequired) {
            ans = 0;
        } else {
            // Check if minimum number of taps attained for current amount @ current level
            if (memo[currAmt][currLevel] > 0) {
                return memo[currAmt][currLevel];
            }

            // Check for all possible upgrades, and minimum number of taps attained for each
            // upgrade
            int lowestTaps, numTaps, numTapsUpgrade;
            double diff, valPerTap;

            diff = amountRequired - currAmt;
            valPerTap = values[currLevel];
            if (isTest) {
                System.out.println("diff = " + diff + ", valPerTap = " + valPerTap);
            }
            numTapsUpgrade = (int) Math.ceil(diff / valPerTap);
            lowestTaps = numTapsUpgrade;

            int nextLevel = currLevel + 1;
            for (int i = nextLevel; i <= maxLevel; i++) {
                diff = costs[i] - currAmt;
                valPerTap = values[currLevel];
                numTapsUpgrade = (int) Math.ceil(diff / valPerTap);
                // If current amount > cost, no need to tap to upgrade
                if (numTapsUpgrade < 0) {
                    numTapsUpgrade = 0;
                }

                // Obtain number of taps after upgrading
                numTaps = numTapsUpgrade + helper(i, maxLevel, currAmt + numTapsUpgrade * values[currLevel] - costs[i],
                        amountRequired, memo, values, costs);
                lowestTaps = Math.min(lowestTaps, numTaps);
            }
            ans = lowestTaps;
        }
        memo[currAmt][currLevel] = ans;
        return ans;
    }

    private void run() {
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
        for (int tc = 0; tc < testCases; tc++) {
            int maxLevel = sc.nextInt();
            int amountRequired = sc.nextInt();
            int[] values = new int[maxLevel + 1];
            for (int i = 0; i <= maxLevel; i++) {
                values[i] = sc.nextInt();
            }
            int[] costs = new int[maxLevel + 1];
            for (int i = 0; i <= maxLevel; i++) {
                costs[i] = sc.nextInt();
            }
            int solution = calculateMinimum(maxLevel, amountRequired, values, costs);
            System.out.println(solution);
        }
        sc.close();
    }

    public static void main(String[] args) {
        IdleGame obj = new IdleGame();
        obj.run();
    }
}
