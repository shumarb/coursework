// Copy paste this Java Template and save it as "Supermarket.java"
import java.io.*;
import java.util.*;

// write your matric number here: A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here: Ho Wei Chin
// year 2018 hash code: AwrBr3czNrkqgCv4HeF3 (do NOT delete this line)

class Supermarket {
    private ArrayList < Integer > path;
    private boolean isTest = false;
    private boolean[] hasVisitedArray;
    private int INF = Integer.MAX_VALUE;
    private int K; // the number of items that Ketfah has to buy
    private int minCost;
    private int N; // number of items in the supermarket. V = N+1 
    private int[] shoppingList; // indices of items that Ketfah has to buy
    private int[][] M; // T and M are the complete weighted graph that measures the direct wheeling time to go from one point to another point in seconds
    private int[][] reducedGraph;
    private int[][] T; // T and M are the complete weighted graph that measures the direct wheeling time to go from one point to another point in seconds

    int Query() {
        hasVisitedArray = new boolean[T.length];
        path = new ArrayList <> ();
        M = new int[T.length][T.length];
        reducedGraph = new int[1 + shoppingList.length][1 + shoppingList.length];
        minCost = INF;

        if (isTest) {
            displaysTAndShoppingList();
        }
        initM();
        if (isTest) {
            System.out.println("Before Floyd-Warshall: ");
            displaysGraph(M);
        }
        floydWarshall();
        if (isTest) {
            System.out.println("After Floyd-Warshall: ");
            displaysGraph(M);
            System.out.println();
        }
        fillsReducedGraph();
        backtracking(0);  
        return minCost;
    }

    /**
     * Finds optimal path in reducedGraph
     * Precon: reducedGraph correctly filled up
     * Postcon: minCost obtained
     */
    private void backtracking(int u) {
        // Step 1: Add u to path and mark it as visited
        path.add(u);
        hasVisitedArray[u] = true;

        // Step 2: Check if all vertices in reduced Graph is visited
        boolean isAllVisited = true;

        for (int i = 0; i < shoppingList.length; i++) {
            if (isTest) {
                System.out.print("shoppingList[" + i + "]: " + shoppingList[i]);
                System.out.println(", visited[" + shoppingList[i] + "]: " + hasVisitedArray[shoppingList[i]]);
            }
            if (!hasVisitedArray[shoppingList[i]]) {
                isAllVisited = false;
                break;
            }
        }

        if (isAllVisited) {
            if (isTest) {
                displaysPath(path);
            }
            updatesMinCost(path);
        }
        else {
            for (int i = 0; i < shoppingList.length; i++) {
                if (!hasVisitedArray[shoppingList[i]]) {
                    backtracking(shoppingList[i]);
                }
            }
        }
        hasVisitedArray[u] = false;
        path.remove(path.size() - 1);
    }

    /**
     * Updates Minimum Cost
     * Precon: Path from vertex 0 to all vertices in shopping list and
     * back to source vertex found
     * Postcon: minCost updated
     */
    private void updatesMinCost(ArrayList < Integer > path) {
        int cost = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            int curr = path.get(i);
            int next = path.get(i + 1);
            int index1 = findsIndex(curr);
            int index2 = findsIndex(next);
            if (isTest) {
                System.out.println("curr = " + curr + ", index1 = " + index1);
                System.out.println("next = " + next + ", index2 = " + index2);
            }
            if (index1 == -1) {
                cost += reducedGraph[0][index2];
            }   
            if (index1 != -1 && index2 != -1) {
                cost += reducedGraph[index1][index2];
            }
            if (isTest) {
                System.out.println("so far, cost = " + cost);
            }
        }
        int last = path.get(path.size() - 1);
        int indexLast = findsIndex(last);
        if (isTest) {
            System.out.println("last = " + last + ", indexLast = " + indexLast);
        }
        cost += reducedGraph[indexLast][0];
        if (isTest) {
            System.out.println("so far, cost = " + cost);
            System.out.println("Before comparison, cost = " + cost + ", minCost = " + minCost);
        }
        minCost = Math.min(minCost, cost);
        if (isTest) {
            System.out.println("After comparison, minCost = " + minCost);
        }
    }

    /**
     * Finds index of vertex in shoppingList
     * Precon: A path from source vertex to all vertices in shopping
     * List and back to source vertex
     * Postcon: Index of vertex in shoppingList found
     */
    private int findsIndex(int vertex) {
        for (int i = 0; i < shoppingList.length; i++) {
            if (shoppingList[i] == vertex) {
                return i + 1;
            }
        }
        return -1;
    }

    /**
     * Displays path found
     * Precon: test==true 
     * Postcon: nil
     */
    private static void displaysPath(ArrayList <Integer> path) {
        System.out.print("Path: ");
        for (int i = 0; i < path.size(); i++) {
            System.out.print(path.get(i) + " ");
        }
        System.out.println(0);
    }

    /**
     * Fills up reduced Graph matrix
     * Precon: floyd Warshall matrix M filled up
     * Postcon: reducedGraph matrix filled up
     */
    private void fillsReducedGraph() {
        // Fills up first row and column
        for (int i = 1; i < K + 1; i++) {
            reducedGraph[0][i] = M[0][shoppingList[i - 1]];
            reducedGraph[i][0] = reducedGraph[0][i];
        }

        // Fill up all cells NOT in first row & first column
        for (int i = 1; i < K + 1; i++) {
            for (int j = 1; j < K + 1; j++) {
                reducedGraph[i][j] = M[shoppingList[i - 1]][shoppingList[j - 1]];
            }
        }
        if (isTest) {
            System.out.println("Reduced Graph: ");
            displaysGraph(reducedGraph);
        }
    }

    /**
     * Displays graph
     * Precon: test == true
     * Postcon: Nil
     */
    private void displaysGraph(int[][] graph) {
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[i].length; j++) {
                System.out.print(graph[i][j] + " ");
            }
            System.out.println();
        }
    }

    /**
     * Displays M
     * Precon: isTest == true 
     * Postcon: Nil
     */
    private void floydWarshall() {
        for (int k = 0; k < T.length; k++) {
            for (int i = 0; i < T.length; i++) {
                for (int j = 0; j < T.length; j++) {
                    M[i][j] = Math.min(M[i][j], (M[i][k] + M[k][j]));
                }
            }
        }
    }

    /**
     * Initialiazes M
     * Precon: Graph stored in adjMatrix
     * Postcon: Nil
     */
    private void initM() {
        for (int i = 0; i < M.length; i++) {
            M[i][i] = 0;
        }
        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[i].length; j++) {
                if (i != j) {
                    M[i][j] = T[i][j];
                }
            }
        }
    }

    /**
     * Displays 2D Matrix T and 1D Shopping List
     * Precon: isTest == true
     * Postcon: Nil
     */
    private void displaysTAndShoppingList() {
        System.out.print("Shopping list: 0 ");
        for (int i = 0; i < shoppingList.length; i++) {
            System.out.print(shoppingList[i] + " ");
        }
        System.out.println(0);
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

            shoppingList = new int[K];
            for (int i = 0; i < K; i++)
                shoppingList[i] = sc.nextInt();
            T = new int[N + 1][N + 1];
            for (int i = 0; i <= N; i++)
                for (int j = 0; j <= N; j++)
                    T[i][j] = sc.nextInt();
            pw.println(Query());
        }

        pw.close();
    }

    public static void main(String[] args) throws Exception
    {
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
