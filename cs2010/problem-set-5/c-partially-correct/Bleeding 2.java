// Copy paste this Java Template and save it as "Bleeding.java"
import java.util.*;
import java.io.*;

// write your matric number here:A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here: https://cpbook.net/#downloads
// year 2018 hash code: h7my92W5hykxBmUZwVxB (do NOT delete this line)

public class Bleeding {

    private int V; // number of vertices in the graph (number of junctions in Singapore map)
    private int Q; // number of queries
    private Vector <Vector< IntegerPair >> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge
    private PriorityQueue < IntegerPair > pqueue;
    private ArrayList< Integer > dist;
    private ArrayList< ArrayList < Integer > > twoDAdjList;
    private int INF = Integer.MAX_VALUE;
    private boolean test = false;

    void PreProcess() {
        int iterations = Math.min(10,V);
        if (test) {
            System.out.println("iterations = " + iterations);
        }
        twoDAdjList = new ArrayList < ArrayList < Integer > >();
        for(int i = 0; i < iterations; i++){
            twoDAdjList.add(new ArrayList < Integer >());
        }
    }

    int Query(int s, int t, int k) {

        if(s == t) {
            return 0;
        }

        if(twoDAdjList.get(s).size() == 0){
            modifiedDijkstra(s);
            // No path from s to t
            if(twoDAdjList.get(s).get(t) == INF) {
                return -1;
            }
            //return twoDAList.get(s).get(t);
        }
        
        return twoDAdjList.get(s).get(t);
    }
    
    /*
     * Initialization
     * Precon: Source vertex known
     * Postcon: Distance of source vertex is 0
     */
     private void initSSSP(int source) {
        dist = new ArrayList < Integer >();
        dist.addAll(Collections.nCopies(V, INF));
        dist.set(source, 0);
        pqueue = new PriorityQueue<IntegerPair>();
        pqueue.add(new IntegerPair(0, source)); //(weight, neighbour node)
     }

    void modifiedDijkstra(int source){
        // Step 1: Initialize distance array,
        // set distance of source to 0 and add it to queue
        initSSSP(source);
        
        // Step 2: Do Dijkstra Algo
        while(!pqueue.isEmpty()){
            
            // Step 2.1: Obtain first element in queue
            IntegerPair currWeightVert = pqueue.poll();

            int currVert = currWeightVert.second();
            int weight = currWeightVert.first();
            if (test) {
                System.out.println("currVert = " + currVert + ", weight = " + weight);
            }

            // Important check
            if(weight > dist.get(currVert)) {
                continue;
            }
            
            // Step 2.2: Obtain neighbours of current vertex,
            // and check if relaxation can be done. If yes,
            // add neighbour to pqueue
            Iterator< IntegerPair > iter = AdjList.get(currVert).iterator();
            while(iter.hasNext()) {
                IntegerPair p = iter.next();

                int weight_currVert_v = p.second();
                int v = p.first();
                if (test) {
                    System.out.println("v = " + v + ", weight = " + weight_currVert_v);
                }

                if(dist.get(v) > dist.get(currVert) + weight_currVert_v ) {
                    dist.set(v,dist.get(currVert) + weight_currVert_v );
                    int newDistOfV = dist.get(v);
                    pqueue.offer(new IntegerPair(newDistOfV, v));
                }
            }
        }
        // Update source vertex with the distance value
        twoDAdjList.set(source,dist);
    }

    void run() throws Exception {
        // you can alter this method if you need to do so
        IntegerScanner sc = new IntegerScanner(System.in);
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int TC = sc.nextInt(); // there will be several test cases
        while (TC-- > 0) {
            V = sc.nextInt();

            // clear the graph and read in a new graph as Adjacency List
            AdjList = new Vector < Vector < IntegerPair > >();
            for (int i = 0; i < V; i++) {
                AdjList.add(new Vector < IntegerPair >());

                int k = sc.nextInt();
                while (k-- > 0) {
                    int j = sc.nextInt(), w = sc.nextInt();
                    AdjList.get(i).add(new IntegerPair(j, w)); // edge (road) weight (in minutes) is stored here
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



class IntegerPair implements Comparable < IntegerPair > {
    Integer _first, _second;

    public IntegerPair(Integer f, Integer s) {
        _first = f;
        _second = s;
    }

    public int compareTo(IntegerPair o) {
        if (!this.first().equals(o.first()))
            return this.first() - o.first();
        else
            return this.second() - o.second();
    }

    Integer first() { return _first; }
    Integer second() { return _second; }
}
