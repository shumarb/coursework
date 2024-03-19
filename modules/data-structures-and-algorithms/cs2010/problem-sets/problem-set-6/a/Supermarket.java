// Copy paste this Java Template and save it as "Supermarket.java"
import java.io.*;
import java.util.*;

// write your matric number here: A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here:
// year 2018 hash code: AwrBr3czNrkqgCv4HeF3 (do NOT delete this line)

class Supermarket {
    private ArrayList <Integer> path;
    private boolean isTest = false;
    private boolean[] hasVisitedArray;
    private int INF = Integer.MAX_VALUE;
    private int K; // the number of items that Ketfah has to buy;
    private int minCost;
    private int N; // number of items in the supermarket. V = N+1 
    private int[][] T; // the complete weighted graph that measures the direct wheeling time to go from one point to another point in seconds

    int Query() {
        hasVisitedArray = new boolean[T.length];
        minCost = INF;
        path = new ArrayList <> ();

        if (isTest) {
            displaysTAndShoppingList();
        }

        backtracking(0); // Source vertex is vertex 0
        return minCost;
    }
    
    /**
     * Finds minCost of path from vertex 0 to all other vertices and
     * back to vertex 0
     * Precon: Graph stored in adjacency matrix and visited, path,
     * minCost have been initialized
     * Postcon: minCost found
     */
    private void backtracking(int u) {
        // Step 1: Add u to path and mark u as visited
        path.add(u);
        hasVisitedArray[u] = true;

        // Step 2: Check if all vertices have been visited.
        // If yes, a path is found
        boolean hasVisitedAllVertices = true;
        for (int v = 0; v < hasVisitedArray.length; v++) {
            if (!hasVisitedArray[v]) {
                hasVisitedAllVertices = false;
                break;
            }
        }

        // Step 3: If all vertex has been visited, a path is found
        // so update minCost, else go to step 4
        if (hasVisitedAllVertices) {
            if (isTest) {
                displaysPath(path);
            }

            int cost = 0;
            for (int i = 0; i < path.size() - 1; i++) {
                int curr = path.get(i);
                int next = path.get(i + 1);
                cost += T[curr][next];
            }

            // Obtain last vertex in path (Always not source vertex)
            int last = path.get(path.size() - 1);
            cost += T[last][0]; // Add weight from last vertex in path to source vertex
            if (isTest) {
                System.out.println("Before comparison, cost = " + cost + ", minCost = " + minCost);
            }
            minCost = Math.min(minCost, cost);
            if (isTest) {
                System.out.println("After comparison, minCost = " + minCost);
            }
        }
        // If there exist an unvisited vertex, go visit it
        else {
            for (int v = 0; v < hasVisitedArray.length; v++) {
                if (!hasVisitedArray[v]) {
                    backtracking(v);
                }
            }
        }

        // Always mark current vertex as unvisited, and remove last
        // vertex in path
        hasVisitedArray[u] = false;
        path.remove(path.size() - 1);
    }

    /**
     * Displays path
     * Precon: All vertices visited
     * Postcon: Nil
     */
    private void displaysPath(ArrayList <Integer> path) {
        System.out.print("Path: ");
        for (int i = 0; i < path.size() - 1; i++) {
            System.out.print(path.get(i) + " ");
        }
        System.out.println(0); // Last vertex of path always source vertex 0
    }

    /**
     * Displays 2D Matrix T and 1D Shopping List
     * Precon: isTest == true
     * Postcon: Nil
     */
    private void displaysTAndShoppingList() {
        System.out.println("Shopping list: ");
        for (int i = 0; i < hasVisitedArray.length; i++) {
            System.out.println("visited[" + i + "]: " + hasVisitedArray[i]);
        }
        System.out.println("T: ");
        for (int i = 0; i < T.length; i++) {
            for (int j = 0; j < T[i].length; j++) {
                System.out.print(T[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    void run() throws Exception {
        // do not alter this method to standardize the I/O speed
        // (this is already very fast)
        IntegerScanner sc = new IntegerScanner(System.in);
        PrintWriter pw = new PrintWriter(new
                BufferedWriter(new OutputStreamWriter(System.out)));

        int TC = sc.nextInt(); // there will be several test cases
        while (TC-- > 0) {
            // read the information of the
            // complete graph with N+1
            // vertices
            N = sc.nextInt();
            K = sc.nextInt(); // K is the number of items to be bought

            int[] shoppingList = new int[K];
            for (int i = 0; i < K; i++)
                shoppingList[i] = sc.nextInt();

            T =  new int[N + 1][N + 1];
            for (int i = 0; i <= N; i++)
                for (int j = 0; j <= N; j++)
                    T[i][j] = sc.nextInt();
            pw.println(Query());
        }

        pw.close();
    }

    public static void main(String[] args) throws Exception {
        // do not alter this method
        Supermarket ps6 = new Supermarket();
        ps6.run();
    }
}

class IntegerScanner {
    // coded by Ian Leow, using any other I/O method is not recommended
    BufferedInputStream bis;
    IntegerScanner(InputStream is) {
        bis = new BufferedInputStream(is, 1000000);
    }

    public int nextInt() {
        int result = 0;
        try {
            int cur = bis.read();
            if (cur == -1) {
                return -1;
            }

            while ((cur < 48 || cur > 57) && cur != 45) {
                cur = bis.read();
            }

            boolean negate = false;
            if (cur == 45) {
                negate = true;
                cur = bis.read();
            }

            while (cur >= 48 && cur <= 57) {
                result = result * 10 + (cur - 48);
                cur = bis.read();
            }

            if (negate) {
                return -result;
            }
            return result;
        }
        catch (IOException ioe) {
            return -1;
        }
    }
}
