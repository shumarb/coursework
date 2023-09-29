import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here:
// year 2018 hash code: h7my92W5hykxBmUZwVxB (do NOT delete this line)

class Bleeding {
    private boolean isTest = false;
    private int V; // number of vertices in the graph (number of junctions in Singapore map)
    private int Q; // number of queries    
    // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge
    private int[] p, D;
    private int[][] adjMatrix;
    private int INF = Integer.MAX_VALUE;
    private List <IntegerPair> queue;
    private List < Vector <Integer> > adjList;

    /**
     * Displays adjList
     * Precon: isTest  ==  true
     * Postcon: Nil
     */
    private void displaysadjList() {
        System.out.println("Adj List: ");
        for (int i = 0; i < adjList.size(); i++) {
            System.out.print("Vertex " + i + ": ");
            Vector <Integer> currentIntegerPair = adjList.get(i);
            for (int j = 0; j < currentIntegerPair.size(); j++) {
                Integer neighbour = currentIntegerPair.get(j);
                System.out.print(neighbour + " - Weight: " + adjMatrix[i][neighbour] + "; ");
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Displays adjMatrix
     * Precon: isTest  ==  true
     * Postcon: Nil
     */
    private void displaysAdjMatrix() {
        System.out.println("Adj Matrix: ");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    void PreProcess() {
        if (isTest) {
            displaysadjList();
            displaysAdjMatrix();
        }
    }

    /**
     * Displays distance and predecessor arrays
     * Precon: isTest == true
     * Postcon: Nil
     */
    private void displaysArrays() {
        System.out.println("Distance array: ");
        for (int i = 0; i < D.length; i++) {
            System.out.println("D[" + i + "] = " + D[i]);
        }
        System.out.println("Predecessor array: ");
        for (int i = 0; i < p.length; i++) {
            System.out.println("p[" + i + "] = " + p[i]);
        }
    }

    /**
     * Displays Queue
     * Precon: isTest == true
     * Postcon: Nil
     */
    private void displaysQueue() {
        System.out.println("Queue: ");
        Iterator iter = queue.iterator();
        while (iter.hasNext()) {
            IntegerPair currentIntegerPair = (IntegerPair) iter.next();
            System.out.println(currentIntegerPair.getsFirst() + " - D[" + currentIntegerPair.getsSecond() + "]");
        }
    }
    
    /**
     * Edits queue
     * Precon: > 0 elements in queue
     * Postcon: Queue is updated
     */
     private void editsQueue(int s, int val) {
        Iterator iter = queue.iterator();
        while (iter.hasNext()) {
            IntegerPair currentIntegerPair = (IntegerPair) iter.next();
            if (currentIntegerPair.getsSecond() == s) {
                if (isTest) {
                    System.out.println("found");
                }

                currentIntegerPair.setsFirst(val);
                break;
            }
        }
     }

    /**
     * Initialization process
     * Precon: Graph stored in adj list
     * Postcon: Initialization complate
     */
    private void init(int s, int t) {
        D = new int[V];
        p = new int[V];
        queue = new Vector <> ();
        for (int i = 0; i < V; i++) {
            D[i] = INF;
            p[i] = -1;
            IntegerPair currentIntegerPairent = new IntegerPair(D[i], i);
            queue.add(currentIntegerPairent);
        }
        if (isTest) {
            System.out.println("Before set: ");
            displaysArrays();
            displaysQueue();
            System.out.println();
        }
        editsQueue(s, 0);
        if (isTest) {
            System.out.println("After set: ");
            displaysArrays();
            displaysQueue();
            System.out.println();
        }
    }
    
    /**
     * Finds vertex with smallest known vertex to source vertex
     * Precon: Queue has > 0 elements
     * Postcon: Nil
     */
     private IntegerPair findsSmallest() {
        IntegerPair smallest = queue.get(0);
        int small = smallest.getsFirst();
        if (queue.size() > 1) {
            for (int j = 1; j < queue.size(); j++) {
                IntegerPair compare = queue.get(j);
                int comp = compare.getsFirst();
                if (comp < small) {
                    smallest = compare;
                }
            }
        }
        return smallest;
     }
    /**
     * Finds shorisTest path from vertex s to vertex t
     * Precon: queue has all vertices ordered in increasing distance
     * from vertex s
     * Postcon: Values of all paths from source vertex to destination vertex known
     */
    private void dijkstra() {
        while (!queue.isEmpty()) {
            IntegerPair smallest = findsSmallest();
            queue.remove(smallest);
            if (isTest) {
                System.out.println("Smallest: " + smallest.getsFirst() + " - D[" + smallest.getsSecond() + "]");
            }
        }
    }

    int patients2DArray(int s, int t, int k) {
        init(s, t);
        dijkstra();
        return -1;
    }

    void run() throws Exception {
        IntegerScanner sc = new IntegerScanner(System.in);
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int TC = sc.nextInt(); // there will be several isTest cases
        while (TC-- > 0) {
            V = sc.nextInt();

            // clear the graph and read in a new graph as Adjacency List
            adjList = new Vector < Vector < Integer > >();
            adjMatrix = new int[V][V];
            for (int i = 0; i < V; i++) {
                adjList.add(new Vector < Integer >());
                int k = sc.nextInt();
                while (k-- > 0) {
                    int j = sc.nextInt(), w = sc.nextInt();
                    adjList.get(i).add(j); // edge (road) weight (in minutes) is stored here
                    adjMatrix[i][j] = w;
                }
            }

            PreProcess(); // optional

            Q = sc.nextInt();
            while (Q-- > 0) {
                pr.println(patients2DArray(sc.nextInt(), sc.nextInt(), sc.nextInt()));
            }

            if (TC > 0) {
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
            if (cur  ==  -1) {
                return -1;
            }

            while ((cur<48 || cur > 57) && cur != 45) {
                cur = bis.read();
            }

            boolean negate = false;
            if (cur  ==  45) {
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

class IntegerPair implements Comparable < IntegerPair > {
    Integer first;
    Integer second;

    public IntegerPair(Integer first, Integer second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(IntegerPair incoming) {
        if (!this.getsFirst().equals(incoming.getsFirst())) {
            return this.getsFirst() - incoming.getsFirst();
        }
        else {
            return this.getsSecond() - incoming.getsSecond();
        }
    }

    Integer getsFirst() { 
        return this.first; 
    }
    
    Integer getsSecond() { 
        return second; 
    }

    void setsFirst(int first) {
        this.first = first;
    }

    void setsSecond(int second) {
        this.second = second;
    }
}
