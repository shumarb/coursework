// Copy paste this Java Template and save it as
// "GettingFromHereToThere.java"
import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here:
// year 2018 hash code: FVZ7FKgjKBghyMkHGu39 (do NOT delete this line) <-- change this

class GettingFromHereToThere {
    private int V; // number of vertices in the graph (number of rooms in the building)
    private boolean test = false;
    private int[][] adjMatrix;
    private int[][] M;

    /*
     * Displays adj list
     * Precon: test==true
     * Postcon: Nil
     */
    private void displaysAdjMatrix(int[][] adjMatrix) {
        System.out.println("Adjacency matrix: ");
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    void PreProcess() {
        if( test ) {
            System.out.println("Adjacency matrix: ");
            displaysAdjMatrix(adjMatrix);
        }
        M = new int[V][V];
        formsM(M);
        if( test ) {
            System.out.println("Before Floyd-Marshall, M: ");
            displaysAdjMatrix(M);
        }
        floydWarshall(M);
        if( test ) {
            System.out.println("After Floyd-Marshall, M: ");
            displaysAdjMatrix(M);
        }
    }

    /**
     * Forms M
     * Precon: Adjacency matrix is formed
     * Postcon: M is formed
     */
    private void formsM(int[][] M) {
        // Set M[i][j]=adjMatrix[i][j] if adjMatrix[i][j] > 0
        // else set to infinity
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if( adjMatrix[i][j] > 0 ) {
                    M[i][j] = adjMatrix[i][j];
                }
                else {
                    M[i][j] = Integer.MAX_VALUE;
                }
            }
        }
    }

    /**
     * Find optimal path using floydWarshall
     * Precon: Graph stored in adj matrix
     * Postcon: Optimal path of every pair of vertices known
     */
    private void floydWarshall(int[][] M) {
        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    M[i][j] = Math.min(M[i][j], Math.max(M[i][k], M[k][j]));
                }
            }
        }
    }

    int Query(int source, int destination) {
        return M[source][destination];
    }

    void run() throws Exception {
        // do not alter this method
        IntegerScanner sc = new IntegerScanner(System.in);
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int TC = sc.nextInt(); // there will be several test cases
        while(TC-- > 0) {
            V = sc.nextInt();

            adjMatrix = new int[V][V];
            for (int i = 0; i < V; i++) {
                int k = sc.nextInt();
                while (k-- > 0) {
                    int j = sc.nextInt(), w = sc.nextInt();
                    adjMatrix[i][j] = w;
                }
            }

            PreProcess();

            int Q = sc.nextInt();
            while(Q-- > 0)
                pr.println(Query(sc.nextInt(), sc.nextInt()));
            pr.println();
        }

        pr.close();
    }

    public static void main(String[] args) throws Exception {
        // do not alter this method
        GettingFromHereToThere ps4 = new GettingFromHereToThere();
        ps4.run();
    }
}

class IntegerScanner { // coded by Ian Leow, using any other I/O method is not recommended
    BufferedInputStream bis;
    IntegerScanner(InputStream is) {
        bis = new BufferedInputStream(is, 1000000);
    }

    public int nextInt() {
        int result = 0;
        try {
            int cur = bis.read();
            if (cur == -1 ) {
                return -1;
            }

            while ((cur < 48 || cur > 57) && cur!=45) {
                cur = bis.read();
            }

            boolean negate = false;
            if(cur == 45) {
                negate = true;
                cur = bis.read();
            }

            while(cur >= 48 && cur <= 57) {
                result = result * 10 + (cur - 48);
                cur = bis.read();
            }

            if(negate) {
                return -result;
            }
            return result;
        }   
        catch (IOException ioe) {
            return -1;
        }
    }
}

class IntegerPair implements Comparable < IntegerPair > {
    Integer _first, _second;

    public IntegerPair(Integer f, Integer s) {
        _first = f;
        _second = s;
    }

    public int compareTo(IntegerPair o) {
        if(!this.first().equals(o.first())) {
            return o.second() - this.second();
        }
        else {
            return o.first() - this.first();
        }
    }

    Integer first() { return _first; }
    Integer second() { return _second; }
}

class IntegerTriple implements Comparable < IntegerTriple > {
    Integer _first, _second, _third;

    public IntegerTriple(Integer f, Integer s, Integer t) {
        _first = f;
        _second = s;
        _third = t;
    }

    public int compareTo(IntegerTriple o) {
        if(!this.first().equals(o.first())) {
            return this.first() - o.first();
        }
        else if(!this.second().equals(o.second())) {
            return this.second() - o.second();
        }
        else {
            return this.third() - o.third();
        }
    }
    Integer first() { return _first; }
    Integer second() { return _second; }
    Integer third() { return _third; }
}
