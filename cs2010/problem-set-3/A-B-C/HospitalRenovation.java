// Copy paste this Java Template and save it as
// "HospitalRenovation.java"
import java.util.*;
import java.io.*;

class HospitalRenovation {
    private Scanner sc = new Scanner(System.in);
    private boolean test = false;
    private int V, Q, time;

    public static void main(String[] args) throws Exception {
        // do not alter this method
        HospitalRenovation ps3 = new HospitalRenovation();
        ps3.run();
    }

    /**
     * Displays adjacency list
     * Precon: test==true
     * Postcon: Nil
     */
    private void displaysList(ArrayList<ArrayList<Integer>> adjacencyList) {
        for(int i = 0; i<adjacencyList.size(); i++) {
            ArrayList curr = adjacencyList.get(i);
            System.out.print("Vertex " + i + " neighbours: ");
            for(int j = 0; j<curr.size(); j++){
                System.out.print(curr.get(j) + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Forms adjacency list
     * Precon: Adjacency list is empty
     * Postcon: Adjacency list is not empty
     */
    private void formsAdjacencyList(ArrayList<ArrayList<Integer>> adjacencyList) {
        for(int i = 0; i<V; i++) {
            ArrayList<Integer> curr = new ArrayList<Integer>();
            int numNeighbours = sc.nextInt();
            for(int j = 0; j<numNeighbours; j++) {
                int vertex = sc.nextInt();
                curr.add(vertex);
            }
            adjacencyList.add(curr);
        }

        if( test ){
            System.out.println("Adjacency List: ");
            displaysList(adjacencyList);
        }
    }

    /**
     * Reads rating of a room and stores it in a treemap
     * Precon: Number of queries is known
     * Postcon: Rating of every room is known
     */
    private void processesQuery() {
        V = sc.nextInt();
        if(test){
            System.out.println("V = " + V);
        }
        HashMap<Integer, Integer> vertexRating = new HashMap<Integer, Integer>();
        for(int i = 0; i<V; i++) {
            int rating = sc.nextInt();
            vertexRating.put(new Integer(i), new Integer(rating));
        }
        if(test) {
            System.out.println("vertexRating: " + vertexRating);
        }

        ArrayList<ArrayList<Integer>> adjacencyList = new ArrayList<ArrayList<Integer>>();
        formsAdjacencyList(adjacencyList);
        ArrayList<Integer> criticalRooms = new ArrayList<Integer>();
        criticalRooms = findsCriticalRooms(adjacencyList);
        if( test ) {
            System.out.println("critical Rooms: " + criticalRooms);
        }
        if( criticalRooms.isEmpty() ) {
            System.out.println(-1);
        }
        else{
            findsLowestRating(criticalRooms, vertexRating);
        }
    }
    
    /**
     * Finds critical room with lowest rating
     * Precon: Number of critical rooms > 0
     * Postcon: Level of critical room with lowest level is printed
     */
    private void findsLowestRating(ArrayList<Integer> criticalRooms, HashMap<Integer, Integer> rating) {
       int firstRoom = criticalRooms.get(0);
       int lowestLevel = rating.get((Integer) firstRoom);
       if( test ) {
            System.out.println("Vertex " + firstRoom + ": " + lowestLevel);
       }
       for(int i = 1; i<criticalRooms.size(); i++) {
            int compare = criticalRooms.get(i);
            int level = rating.get((Integer) compare);
            if( test ) {
                System.out.println("Vertex " + compare + ": " + level);
            }
            if( level < lowestLevel ) {
                lowestLevel = level;
            }
       }
       System.out.println(lowestLevel);
    }

    /* Finds critical rooms
     * Precon: Adjacency list has been formed
     * Postcon: Critical rooms have been identified
     */
    private ArrayList<Integer> findsCriticalRooms(ArrayList<ArrayList<Integer>> adjList) {
        ArrayList<Integer> criticalRooms = new ArrayList<Integer>();
        HashSet<Integer> visited = new HashSet<Integer>();
        int[] disc = new int[V];
        int[] low = new int[V];
        int parent[] = new int[V];

        for(int i = 0; i < V; i++) {
            parent[i] = -1; // -1 indicates a vertex has no parent
        }

        // Calls recursive helper method to find critical rooms
        for(int i = 0; i < V; i++) {
            // Visit a vertex if it is unvisited
            if( visited.contains(i)==false ) {
                helper(i, adjList, visited, disc, low, parent, criticalRooms);
            }
        }
        
        return criticalRooms;
    }

    /* Helper for findsCriticalRooms
     * Precon: Vertex x is unvisited
     * Postcon: Vertex is a critical room
     */
    private void helper(int x, ArrayList<ArrayList<Integer>> adjList, HashSet<Integer> visited, int[] low, int[] disc, int[] parent, ArrayList<Integer> criticalRooms) {
        // Always mark current vertex at visited at the start of method
        if( visited.contains(x)==false ) {
            visited.add(x);
            if( test ) {
                System.out.println("visited: " + visited);
            }
        }

        // Get adjacency list of current vertex
        ArrayList<Integer> curr = adjList.get(x);

        // Set number of children of current vertex
        int children = 0;

        // Initialize discovery, time, and low values
        disc[x] = low[x] = ++time;

        // Go through all neighbours of current vertex
        for(int j = 0; j<curr.size(); j++) {
            if( test ) {
                System.out.print("Vertex " + x + ":" );
            }   
            int neighbour = curr.get(j);
            if( test ) {
                System.out.print(neighbour + " ");
            }

            // If neighbour has not been visited, go to that neighbour
            if( visited.contains(neighbour)==false ) {
                children++;
                parent[neighbour] = x; // Set x as parent of neighbour
                helper(neighbour, adjList, visited, low, disc, parent, criticalRooms);
            
                // Check if subtree rooted with neighbour has a
                // connection to one of the ancestors of current vertex
                low[x] = Math.min(low[x], low[neighbour]);
                
                // current vertex is a critical room if
                // it is root in DFS tree and has >=2 children
                if( parent[x] == -1 && children >=2 ) {
                    criticalRooms.add(x);
                }

                // current vertex is a critical room if it is not root
                // of DFS and low value of one of its children >
                // discovery value of u
                if( parent[x]!=-1 && low[neighbour] >= disc[x] ) {
                    criticalRooms.add(x);
                }
            }

            // Update low value of u for parent function calls
            else if( neighbour != parent[x] ) {
                low[x] = Math.min(low[x], disc[neighbour]);
            }
        }
    }

    private void run() {
        Q = sc.nextInt();
        for(int i = 0; i<Q; i++) {
            time = 0;
            processesQuery();
        }
    }

}
