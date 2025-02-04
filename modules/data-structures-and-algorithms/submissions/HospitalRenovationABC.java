// Copy paste this Java Template and save it as
// "HospitalRenovationABC.java"
import java.util.*;

// write your matric number here: A0149874L
// write your name here: Sheikh Umar
// write list of collaborators here (The followArraying students answered my
// numQueriesuestions regarding PS3 on the NUS CS2010 FB Group: Daniel Kwang Weide, Iz Ho, Ryan Tal Teo, Enzio Kam Hai Hong
// Website that I referred to: https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
// year 2015 hash code: JESg5svjYpIsmHmIjabX (do NOT delete this line)// <- generate a new hash code

class HospitalRenovation {
    private boolean isTest = false;
    private int numTime = 0;
    private int numVertices;
    private Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        // do not alter this method
        HospitalRenovation ps3 = new HospitalRenovation();
        ps3.run();
    }

    /**
     * Displays adjacency list
     * Precon: isTest == true
     * Postcon: Nil
     */
    private void displaysList(ArrayList<ArrayList <Integer>> adjacencyList) {
        for (int i = 0; i < adjacencyList.size(); i++) {
            ArrayList currentList = adjacencyList.get(i);
            System.out.print("Vertex " + i + " neighbours: ");
            for (int j = 0; j < currentList.size(); j++) {
                System.out.print(currentList.get(j) + " ");
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
    private void formsAdjacencyList(ArrayList<ArrayList <Integer>> adjacencyList) {
        for (int i = 0; i < numVertices; i++) {
            ArrayList <Integer> currentList = new ArrayList <> ();
            int numNeighbours = sc.nextInt();
            for (int j = 0; j < numNeighbours; j++) {
                int numVertex = sc.nextInt();
                currentList.add(numVertex);
            }
            adjacencyList.add(currentList);
        }

        if (isTest) {
            System.out.println("Adjacency List: ");
            displaysList(adjacencyList);
        }
    }

    /**
     * Reads ratingsMap of a room and stores it in a treemap
     * Precon: Number of queries is known
     * Postcon: ratingsMap of every room is known
     */
    private void queriesFirstPatient() {
        numVertices = sc.nextInt();
        if (isTest) {
            System.out.println("V = " + numVertices);
        }
        HashMap <Integer, Integer> vertexRatingsMap = new HashMap <> ();
        for (int i = 0; i < numVertices; i++) {
            int ratingsMap = sc.nextInt();
            vertexRatingsMap.put(i, ratingsMap);
        }
        if (isTest) {
            System.out.println("vertexRatingsMap: " + vertexRatingsMap);
        }

        ArrayList <ArrayList <Integer>> adjacencyList = new ArrayList <ArrayList <Integer>> ();
        formsAdjacencyList(adjacencyList);
        ArrayList <Integer> criticalRoomsList = findsCriticalRoomsList(adjacencyList);
        if (isTest) {
            System.out.println("critical Rooms: " + criticalRoomsList);
        }
        if (criticalRoomsList.isEmpty()) {
            System.out.println(-1);
        } else {
            findsLowestRatingLevel(criticalRoomsList, vertexRatingsMap);
        }
    }
    
    /**
     * Finds critical room with lowest rating level
     * Precon: Number of critical rooms > 0
     * Postcon: Level of critical room with lowest rating level is printed
     */
    private void findsLowestRatingLevel(ArrayList <Integer> criticalRoomsList, HashMap <Integer, Integer> ratingsMap) {
       int firstRoom = criticalRoomsList.get(0);
       int lowestRatingLevel = ratingsMap.get(firstRoom);
       if (isTest) {
            System.out.println("Vertex " + firstRoom + ": " + lowestRatingLevel);
       }
       for (int i = 1; i < criticalRoomsList.size(); i++) {
            int compare = criticalRoomsList.get(i);
            int level = ratingsMap.get(compare);
            if (isTest) {
                System.out.println("Vertex " + compare + ": " + level);
            }
            if (level < lowestRatingLevel) {
                lowestRatingLevel = level;
            }
       }
       System.out.println(lowestRatingLevel);
    }

    /* Finds critical rooms
     * Precon: Adjacency list has been formed
     * Postcon: Critical rooms have been identified
     */
    private ArrayList <Integer> findsCriticalRoomsList(ArrayList <ArrayList <Integer>> adjList) {
        ArrayList <Integer> criticalRoomsList = new ArrayList <> ();
        HashSet <Integer> visitedSetSet = new HashSet <> ();
        int[] discoveryArray = new int[numVertices];
        int[] lowArray = new int[numVertices];
        int[] parentArrayArray = new int[numVertices];

        for (int i = 0; i < numVertices; i++) {
            parentArrayArray[i] = -1; // -1 indicates a vertex has no parentArray
        }

        // Calls recursive helper method to find critical rooms
        for (int i = 0; i < numVertices; i++) {
            // Visit a vertex if it is unvisitedSet
            if (!visitedSetSet.contains(i)) {
                helper(i, adjList, visitedSetSet, discoveryArray, lowArray, parentArrayArray, criticalRoomsList);
            }
        }
        
        return criticalRoomsList;
    }

    /* Helper for findsCriticalRoomsList
     * Precon: Vertex x is unvisitedSet
     * Postcon: Vertex is a critical room
     */
    private void helper(int x, ArrayList<ArrayList <Integer>> adjList, HashSet <Integer> visitedSet, 
                        int[] lowArray, int[] discoveryArray, int[] parentArray, ArrayList <Integer> criticalRoomsList) {
        // Always mark current vertex at visitedSet at the start of method
        if (!visitedSet.contains(x)) {
            visitedSet.add(x);
            if (isTest) {
                System.out.println("visitedSet: " + visitedSet);
            }
        }

        // Get adjacency list of current vertex
        ArrayList <Integer> currentList = adjList.get(x);

        // Set number of numChildren of current vertex
        int numChildren = 0;

        // Initialize discovery, numTime, and lowArray values
        discoveryArray[x] = lowArray[x] = ++numTime;

        // Go through all neighbours of current vertex
        for (int j = 0; j < currentList.size(); j++) {
            if (isTest) {
                System.out.print("Vertex " + x + ":");
            }   
            int neighbour = currentList.get(j);
            if (isTest) {
                System.out.print(neighbour + " ");
            }

            // If neighbour has not been visitedSet, go to that neighbour
            if (!visitedSet.contains(neighbour)) {
                numChildren++;
                parentArray[neighbour] = x; // Set x as parentArray of neighbour
                helper(neighbour, adjList, visitedSet, lowArray, discoveryArray, parentArray, criticalRoomsList);
            
                // Check if subtree rooted with neighbour has a
                // connection to one of the ancestors of current vertex
                lowArray[x] = Math.min(lowArray[x], lowArray[neighbour]);
                
                // current vertex is a critical room if
                // it is root in DFS tree and has >=2 numChildren
                if (parentArray[x] == -1 && numChildren >=2) {
                    criticalRoomsList.add(x);
                }

                // current vertex is a critical room if it is not root
                // of DFS and lowArray value of one of its numChildren >
                // discovery value of u
                if (parentArray[x] != -1 && lowArray[neighbour] >= discoveryArray[x]) {
                    criticalRoomsList.add(x);
                }
            } else {
                if (neighbour != parentArray[x]) {
                    // Update lowArray value of u for parentArray function calls
                    lowArray[x] = Math.min(lowArray[x], discoveryArray[neighbour]);
                }
            }
        }
    }

    /* Closes scanner
     * Precon: All numQueries processed
     * Postcon: End of program
     */
    private void closesScanner() {
        sc.close();
    }

    /**
     * Processes numQueries
     * Precon: numQueries > 0
     * Postcon: Closes scanner
     */
    private void processesNumQueries(int numQueries) {
        for (int i = 0; i < numQueries; i++) {
            queriesFirstPatient();
        }
    }

    private void run() {
        int numQueries = sc.nextInt();
        processesNumQueries(numQueries);
        closesScanner();
    }
}
