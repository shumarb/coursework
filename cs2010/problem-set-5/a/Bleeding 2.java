import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here: Ho Wei Chin
// year 2018 hash code: h7my92W5hykxBmUZwVxB (do NOT delete this line)

class Bleeding {
    private int V; // number of vertices in the graph (number of junctions in Singapore map)
    private int Q; // number of queries    
    // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge
    private Vector < Vector < IntegerPair > > AdjList;
    private boolean test = false;
    private int[][] query; 
    private int[] p, D;
    private int INF = Integer.MAX_VALUE;

    /**
     * Displays AdjList
     * Precon: test == true
     * Postcon: Nil
     */
    private void displaysAdjList() {
        System.out.println("Adj List: ");
        for(int i = 0; i < AdjList.size(); i++) {
            System.out.print("Vertex " + i + ": ");
            Vector < IntegerPair > curr = AdjList.get(i);
            for(int j = 0; j < curr.size(); j++) {
                IntegerPair neighbour = curr.get(j);
                System.out.print(neighbour.first() + " - Weight: " + neighbour.second() + "; ");
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Displays adjMatrix
     * Precon: test == true
     * Postcon: Nil
     */
    private void displaysQuery() {
        System.out.println("Query: ");
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                System.out.print(query[i][j] + " ");
            }
            System.out.println();
        }
    }

    /**
     * Displays D and p arrays
     * Precon: test==true
     * Postcon: Nil
     */
    private void displaysDandP(int[]D, int[]p) {
        System.out.println("**************************");
        System.out.println("Distance array: ");
        for (int i = 0; i < D.length; i++) {
            System.out.println("D[" + i + "]: " + D[i]);
        }
        System.out.println();
        System.out.println("Predecessor array: ");
        for (int i = 0; i < p.length; i++) {
            System.out.println("p[" + i + "]: " + p[i]);
        }
        System.out.println("**************************");
    }

    /**
     * Do BFS
     * Precon: Graph stored in AdjList
     * Postcon: Modified BFS performed on graph
     */
    private void ModifiedBFS(int source) {
        // Step 1: Initialize D and p arrays
        for (int i = 0; i < V; i++) {
            D[i] = INF;
            p[i] = -1;
        }
        if (test) {
            displaysDandP(D, p);
        }

        // Step 2: Set D[source] = 0;
        D[source] = 0;

        // Step 3: Create Queue for Modified BFS
        Queue < Integer > queue = new LinkedList < Integer > ();

        // Step 4: Apply ModifiedBFS algo
        queue.offer(source);
        while (queue.isEmpty() == false) {
            // Step 4.1: Obtain first element
            int top = queue.poll();

            // Step 4.2: Obtain neighbours of top element
            Vector < IntegerPair > neighboursOfTop = AdjList.get(top);
            if (test) {
                System.out.print("Neighbours of " + top + ": ");
                for (int i = 0; i < neighboursOfTop.size(); i++) {
                    System.out.print(neighboursOfTop.get(i).first() + "; ");
                }
            }

            // Step 4.3: Check if need to relax
            for (int i = 0; i < neighboursOfTop.size(); i++) {
                IntegerPair neighbourEdge = neighboursOfTop.get(i);
                int neighbour = neighbourEdge.first();
                int edge = neighbourEdge.second();
                if (D[neighbour] == INF) {
                    boolean isRelax = relax(top, neighbour, edge);
                    // Step 4.4: If relax operation is successful, add neighbour to queue
                    // and update query array to value of D[neighbour]
                    if (isRelax) {
                        query[source][neighbour] = D[neighbour];
                        queue.offer(neighbour);
                    }
                }
            }
        }
    }

    /**
     * Relax operation
     * Precon: queue is not empty
     * Postcon: Relax operation successfully performed
     */
    private boolean relax(int curr, int neighbour, int edge) {
        // If can relax, up Distance value of neighbour and set
        // neighbour's parent to current vertex
        if (D[neighbour] > D[curr] + edge) {
            D[neighbour] = D[curr] + edge;
            p[neighbour] = curr;
            return true;
        }
        return false;
    }

    void PreProcess() {
        if (test) {
            displaysAdjList();
        }
        query = new int[V][V];
        for (int i = 0; i < V; i++) {
            D = new int[V];
            p = new int[V];
            ModifiedBFS(i);
        }
    }

    int Query(int s, int t, int k) {
        return query[s][t];
    }

    void run() throws Exception {
        IntegerScanner sc = new IntegerScanner(System.in);
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int TC = sc.nextInt(); // there will be several test cases
        while(TC-- > 0) {
            V = sc.nextInt();

            // clear the graph and read in a new graph as Adjacency List
            AdjList = new Vector < Vector < IntegerPair > >();
            for(int i = 0; i < V; i++) {
                AdjList.add(new Vector < IntegerPair >());

                int k = sc.nextInt();
                while(k-- > 0) {
                    int j = sc.nextInt(), w = sc.nextInt();
                    AdjList.get(i).add(new IntegerPair(j, w)); // edge (road) weight (in minutes) is stored here
                }
            }

            PreProcess(); // optional

            Q = sc.nextInt();
            while(Q-- > 0) {
                pr.println(Query(sc.nextInt(), sc.nextInt(), sc.nextInt()));
            }

            if(TC > 0) {
                pr.println();
            }
        }

        pr.close();
    }

    public static void main(String[] args) throws Exception {
        Bleeding ps5 = new Bleeding();
        ps5.run();
    }
}

class IntegerScanner {// coded by Ian Leow, using any other I/O method is not recommended
    BufferedInputStream bis;
    IntegerScanner(InputStream is) {
        bis = new BufferedInputStream(is, 1000000);
    }

    public int nextInt() {
        int result = 0;
        try {
            int cur = bis.read();
            if(cur == -1) {
                return -1;
            }

            while ((cur<48 || cur > 57) && cur != 45) {
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
            return this.first() - o.first();
        }
        else {
            return this.second() - o.second();
        }
    }

    Integer first() { return _first; }
    Integer second() { return _second; }
}
