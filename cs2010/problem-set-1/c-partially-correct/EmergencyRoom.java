// Copy paste this Java Template and save it as "EmergencyRoom.java"
import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: SHEIKH UMAR
// write list of collaborators here:
// year 2018 hash code: FxYTABbg8BUwrG7T76qY (do NOT delete this line)

class EmergencyRoom{
    private boolean test = false;
    private int highestLevel, numPatients = 0;
    private TreeMap <String, Integer> patientsPosition = new TreeMap <String, Integer> ();
    private TreeMap <String, Integer> patientsLevel = new TreeMap <String, Integer> ();
    private String highestName;

    // Display patients in order
    // Precon: test == true
    // Postcon: nil
    private void print(){
        System.out.println("patientsLevel: " + patientsLevel);
        System.out.println("patientsPosition: " + patientsPosition);
        System.out.println("numPatients: " + numPatients);
        System.out.println();
    }

    void UpdateEmergencyLvl(String patientName, int incEmergencyLvl){
        if( test ){
            System.out.println("Before update: ");
            print();
        }
        int newUpdatedVal = patientsLevel.get(patientName).intValue()+incEmergencyLvl;
        patientsPosition.put(patientName, newUpdatedVal);
        patientsLevel.put(patientName, newUpdatedVal);
        if( test ){
            System.out.println("After update: ");
            print();
        }
    }

    private void updatesHighest(String name, int level){
        if( test ){
            System.out.println("Before swap, Highest: " + highestName + ", " + highestLevel);
        }
        highestName = name;
        highestLevel = level;
        if( test ){
            System.out.println("After swap, Highest: " + highestName + ", " + highestLevel);
        }
    }

    void ArriveAtHospital(String patientName, int emergencyLvl) {
        if( patientsLevel.isEmpty() ){
            numPatients+=1;
            patientsLevel.put(patientName, emergencyLvl);
            patientsPosition.put(patientName, numPatients);
            updatesHighest(patientName, emergencyLvl);
        }
        else{
            numPatients+=1;
            patientsLevel.put(patientName, emergencyLvl);
            patientsLevel.put(patientName, emergencyLvl);
            patientsPosition.put(patientName, numPatients);
            if( emergencyLvl > highestLevel ){
                updatesHighest(patientName, emergencyLvl);
            }
            if( emergencyLvl == highestLevel ){
                int incomingQPos = (patientsPosition.get(patientName)).intValue();
                int highestQPos = (patientsPosition.get(highestName)).intValue();
                if( test ){
                    System.out.println("incomingQPos: " + incomingQPos + ", highestQPos: " + highestQPos);
                }
                if( incomingQPos < highestQPos ){
                    updatesHighest(patientName, emergencyLvl);
                }
            }
        }

        if( test ){
            print();
        }
    }

    void Treat(String patientName){
        if( test ){
            System.out.println("To treat: " + patientName);
            System.out.println("Before removal: ");
            print();
        }
        patientsLevel.remove(patientName);
        patientsPosition.remove(patientName);
        numPatients-=1;
        if( test ){
            System.out.println("After removal: ");
            print();
        }
    }

    // Get patient with highest level
    // Precon: User entered 3
    // Postcon: Patient with highest number known
    private String getHighest(){
        String compareName = "][][", maxName = "[][]]";
        int val = 0, max = 0, compareQPos = 0, maxQPos = 0;

        for(String x: patientsLevel.keySet()){
            val = (patientsLevel.get(x)).intValue();
            if( test ){
                System.out.println("To compare: " + x + "-" + val + " || " + maxName + "-" + max);
            }
            if( val > max ){
                max = val;
                maxName = x;
            }
            if( val==max ){
                maxQPos = patientsPosition.get(maxName);
                compareQPos = patientsPosition.get(x);
                if( test ){
                    System.out.println("maxQPos = " + maxQPos + ", compareQPos = " + compareQPos);
                }
                if( compareQPos < maxQPos ){
                    max = val;
                    maxName = x;
                }
            }
            if( test ){
                System.out.println("maxName = " + maxName + ",max = " + max);
            }
        }

        return maxName;
    }

    String Query() {
        if( patientsLevel.isEmpty() ){
            return "The emergency suite is empty";
        }
        else{
            String highest = getHighest();
            if( test ){
                System.out.println("highest =  " + highest);
            }
            return highest;
        }
    }

    void run() throws Exception{
        // do not alter this method

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int numCMD = Integer.parseInt(br.readLine()); // note that numCMD >= N
        while (numCMD-- >0 ){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            switch (command) {
                case 0: ArriveAtHospital(st.nextToken(), Integer.parseInt(st.nextToken())); break;
                case 1: UpdateEmergencyLvl(st.nextToken(), Integer.parseInt(st.nextToken())); break;
                case 2: Treat(st.nextToken()); break;
                case 3: pr.println(Query()); break;
            }
        }
        pr.close();
    }

    public static void main(String[] args) throws Exception{
        // do not alter this method
        EmergencyRoom ps1 = new EmergencyRoom();
        ps1.run();
    }
}
