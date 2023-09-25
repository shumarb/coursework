import java.util.*;

class IdleGame {

    private boolean isTest = false;
    private int max = 0;

    private int calculateMinimum(int maxLevel, int amountRequired, int[] values, int[] costs) {
        max = maxLevel;
        int minTaps = helper(0, 0, 0, amountRequired, values, costs);
        return minTaps;
    }

    private int helper(int numTaps, int currLevel, int currAmt, int amountRequired, int[] values, int[] costs) {
        // If current amount >= amount required, minimum number of taps attained
        if (currAmt >= amountRequired) {
            return numTaps;
        } else {
            // If current level is max level, tap 1 more time
            if (currLevel == max) {
                return helper(numTaps + 1, currLevel, currAmt + values[currLevel], amountRequired, values, costs);
            } else {
                // If current amount if enough to upgrade to next level, obtain numTaps @ every
                // level if upgrade is possible at that level,
                // and compare it with NOT upgrading and tapping @ current level
                int nextLevel = currLevel + 1;
                if (currAmt - costs[nextLevel] >= 0) {
                    ArrayList<Integer> totalTaps = new ArrayList<Integer>();
                    for (int i = nextLevel; i <= max; i++) {
                        if (currAmt - costs[i] >= 0) {
                            int num1 = helper(numTaps, i, currAmt - costs[i], amountRequired, values, costs);
                            totalTaps.add(num1);
                        }
                    }
                    int num2 = helper(numTaps + 1, currLevel, currAmt + values[currLevel], amountRequired, values,
                            costs);
                    totalTaps.add(num2);
                    Collections.sort(totalTaps);
                    if (isTest) {
                        System.out.print("totalTaps: ");
                        for (int i = 0; i < totalTaps.size(); i++) {
                            System.out.print(totalTaps.get(i) + " ");
                        }
                        System.out.println("FINAL numTaps: " + totalTaps.get(0));
                    }
                    return totalTaps.get(0);
                } else {
                    // Tap @ current level 1 more time
                    return helper(numTaps + 1, currLevel, currAmt + values[currLevel], amountRequired, values, costs);
                }
            }
        }
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
