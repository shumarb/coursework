// Copy paste this Java Template and save it as "Bleeding.java"
import java.util.*;
import java.io.*;

// write your matric number here:A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here: https://cpbook.net/#downloads
// year 2018 hash code: h7my92W5hykxBmUZwVxB (do NOT delete this line)

public class Bleeding {
    private ArrayList< Integer > dist;
    private ArrayList< ArrayList < Integer > > twoDadjList;
    private boolean test = false;
    private int INF = Integer.MAX_VALUE;
    private int Q; // number of queries
    private int V; // number of vertices in the graph (number of junctions in Singapore map)
    private PriorityQueue < IntegerPair > priorityQueue;
    private ArrayList <ArrayList< IntegerPair >> adjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge

    void PreProcess() {
        int iterations = Math.min(10,V);
        if (test) {
            System.out.println("iterations = " + iterations);
        }
        twoDadjList = new ArrayList < ArrayList < Integer > >();
        for(int i = 0; i < iterations; i++){
            twoDadjList.add(new ArrayList <> ());
        }
    }

    int Query(int s, int t, int k) {
        if (s == t) {
            return 0;
        }

        if (twoDadjList.get(s).isEmpty()){
            modifiedDijkstra(s);
            // No path from s to t
            if (twoDadjList.get(s).get(t) == INF) {
                return -1;
            }
        }
        
        return twoDadjList.get(s).get(t);
    }
    
    /*
     * Initialization
     * Precon: Source vertex known
     * Postcon: Distance of source vertex is 0
     */
     private void initSSSP(int source) {
        dist = new ArrayList <> ();
        dist.addAll(Collections.nCopies(V, INF));
        dist.set(source, 0);
        priorityQueue = new PriorityQueue <> ();
        priorityQueue.add(new IntegerPair(0, source)); //(weight, neighbour node)
     }

    void modifiedDijkstra(int source){
        // Step 1: Initialize distance array,
        // set distance of source to 0 and add it to queue
        initSSSP(source);
        
        // Step 2: Do Dijkstra Algo
        while (!priorityQueue.isEmpty()){
            
            // Step 2.1: Obtain first element in queue
            IntegerPair currWeightVert = priorityQueue.poll();

            int currVert = currWeightVert.getsSecond();
            int weight = currWeightVert.getsFirst();
            if (test) {
                System.out.println("currVert = " + currVert + ", weight = " + weight);
            }

            // Important check
            if (weight > dist.get(currVert)) {
                continue;
            }
            
            // Step 2.2: Obtain neighbours of current vertex,
            // and check if relaxation can be done. If yes,
            // add neighbour to priorityQueue
            Iterator <IntegerPair> iter = adjList.get(currVert).iterator();
            while (iter.hasNext()) {
                IntegerPair p = iter.next();

                int currentVertexWeight = p.getsSecond();
                int v = p.getsFirst();
                if (test) {
                    System.out.println("v = " + v + ", weight = " + currentVertexWeight);
                }

                if (dist.get(v) > dist.get(currVert) + currentVertexWeight ) {
                    dist.set(v,dist.get(currVert) + currentVertexWeight );
                    int newDistOfV = dist.get(v);
                    priorityQueue.offer(new IntegerPair(newDistOfV, v));
                }
            }
        }
        // Update source vertex with the distance value
        twoDadjList.set(source,dist);
    }

    void run() throws Exception {
        // you can alter this method if you need to do so
        IntegerScanner sc = new IntegerScanner(System.in);
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int TC = sc.nextInt(); // there will be several test cases
        while (TC-- > 0) {
            V = sc.nextInt();

            // clear the graph and read in a new graph as Adjacency List
            adjList = new ArrayList < ArrayList < IntegerPair > >();
            for (int i = 0; i < V; i++) {
                adjList.add(new ArrayList < IntegerPair >());

                int k = sc.nextInt();
                while (k-- > 0) {
                    int j = sc.nextInt(), w = sc.nextInt();
                    adjList.get(i).add(new IntegerPair(j, w)); // edge (road) weight (in minutes) is stored here
                }
            }

            PreProcess(); // optional

            Q = sc.nextInt();
            while (Q-- > 0)
                pr.println(Query(sc.nextInt(), sc.nextInt(), sc.nextInt()));

            if (TC > 0)
                pr.println();
        }

        pr.close();
    }


    public static void main(String[] args) throws Exception {
        // do not alter this method
        Bleeding ps5 = new Bleeding();
        ps5.run();
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
            if (cur == -1)
                return -1;

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

class IntegerPair implements Comparable <IntegerPair> {
    Integer first;
    Integer second;

    public IntegerPair(Integer first, Integer second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(IntegerPair incoming) {
        if (!this.getsFirst().equals(incoming.getsFirst()))
            return this.getsFirst() - incoming.getsFirst();
        else
            return this.getsSecond() - incoming.getsSecond();
    }

    Integer getsFirst() { 
        return this.first; 
    }
    Integer getsSecond() { 
        return this.second; 
    }
}
