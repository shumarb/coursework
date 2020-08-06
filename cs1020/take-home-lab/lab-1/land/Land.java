import java.util.*;

public class Land {

    private boolean isTest = false;

    /**
     * Displays grid
     * Precon: isTest is true
     * Postcon: Nil
     */
    private void displaysGrid(int[][] grid) {
        System.out.println("Final Grid: ");
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }

    /**
     * Forms grid of size N with M cells that correspond to the trees
     * Precon: Grid has not been formed
     * Postcon: Grid has been formed
     */
    private int[][] formsGrid() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[][] grid = new int[N][N];
        if (isTest) {
            System.out.println("N = " + N + ", M = " + M);
        }
        
        // Fills grid with trees in M cells
        for (int i = 0; i < M; i++) {
            int xCoordinate = sc.nextInt();
            int yCoordinate = sc.nextInt();
            grid[xCoordinate - 1][yCoordinate - 1] = -1;
        }
        sc.close();

        if (isTest) {
            System.out.println("Grid: ");
            displaysGrid(grid);
        }

        return grid;
    }

    /**
     * Computes the length of side of largest square with no trees in it
     * Precon: Grid has at least 1 tree
     * Postcon: Nil
     */
    private int computesResult(int[][] grid) {
        // Each cell represents the bottom-right hand corner of the largest possible square that can be
        // formed. Hence, it hold the value of the length of the
        // largest possible square that can be formed.
        int max = 0;

        for (int i = 0; i < grid.length; i++) {
            if (grid[0][i] == 0) {
                grid[0][i] = 1;
                max = 1; // There is at least 1 empty cell
            }
            if (grid[i][0] == 0) {
                grid[i][0] = 1;
                max = 1; // There is at least 1 empty cell
            }
        }

        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                if (grid[i][j] == 0) {
                    int above = grid[i - 1][j];
                    int left = grid[i][j - 1];
                    int diag = grid[i - 1][j - 1];

                    // Set current grid as 1 if cell above, diagonal or left of it is <0
                    if (above < 0 || left < 0 || diag < 0) {
                        grid[i][j] = 1;
                    }

                    // Cells around current cell are >=0. Find minimum
                    // value among above, left, diag
                    else {
                        // If above == left == diag -> left == diag
                        if (above == left && above == diag) {
                            grid[i][j] = 1 + above;
                        }
                        // above, left, and diag are not the same value,
                        // so find the minimum among them, and set
                        // current cell as 1+minimum of the 3.
                        else {
                            grid[i][j] = 1 + Math.min(above, Math.min(left, diag));
                        }
                    }
                }

                if (grid[i][j] > max) {
                    max = grid[i][j];
                }
            }
        }

        return max;
    }

    /**
     * Displays length of size of largest square without trees
     * Precon: Length of size of largest square without trees is at least 1 cell
     * Postcon: Nil
     */
    private void displaysResult(int result) {
        System.out.println(result);
    }

    private void run() {
        int[][] grid = formsGrid();
        int result = computesResult(grid);
        displaysResult(result);
    }

    public static void main(String[] args) {
        Land obj = new Land();
        obj.run();
    }
}

