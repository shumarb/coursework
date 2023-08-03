// Copy paste this Java Template and save it as "EmergencyRoom.java"
import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: SHEIKH UMAR
// write list of collaborators here:
// year 2018 hash code: FxYTABbg8BUwrG7T76qY (do NOT delete this line)

class EmergencyRoom{
    private boolean test = false;
    private ArrayList <Patient> patientsAL = new ArrayList <Patient>();
    private ArrayList <String> patientsOrderOfArrival = new ArrayList <String> ();
    private HashMap <String, Integer> patientsHMap = new HashMap <String, Integer> ();

    private class Patient{
        private String _name;
        private int _level;

        private Patient(String name, int lvl){
            this._name = name;
            this._level = lvl;
        }
    }

    // Display patients in order
    // Precon: test == true
    // Postcon: nil
    private void print(){
        int count = 1;
        System.out.println("patientsAL: ");
        for(int i = 0; i<patientsAL.size(); i++){
            System.out.print("Patient " + count++ + ": ");
            Patient patient = patientsAL.get(i);
            System.out.println(patient._name + " " + patient._level);
        }
        System.out.println("patientsHMap: " + patientsHMap);
        System.out.println("patientsOrderOfArrival: " + patientsOrderOfArrival);
        System.out.println();
    }

    void UpdateEmergencyLvl(String patientName, int incEmergencyLvl){
        int originalVal = (patientsHMap.get(patientName)).intValue(), updatedVal = originalVal + incEmergencyLvl;
        if( updatedVal > 100 ){
            updatedVal = 100;
        }
        if( test ){
            System.out.println("To update: " + patientName);
            System.out.println("originalVal = " + originalVal + ", updatedVal = " + updatedVal);
            System.out.println("Before update, patientsHMap: " + patientsHMap);
        }
        patientsHMap.put(patientName, updatedVal);
        if( test ){
            System.out.println("After update, patientsHMap: " + patientsHMap);
        }
        removesPatient(patientName);
        Patient updated = new Patient(patientName, updatedVal);
        if( test ){
            System.out.println("To add updated: " + patientName + ", " + updatedVal);
        }
        storesPatient(updated);
        if( test ){
            System.out.println("After updating: ");
            print();
        }
    }

    /* Put patient into queue
     * Precon: Patient has arrived at hospital
     * Postcon: Patient is in correct position of queue
     */
    private void storesPatient(Patient incoming){
        if( patientsAL.isEmpty() ){
            patientsAL.add(incoming);
            patientsHMap.put(incoming._name, incoming._level);
        }
        else{
            boolean stop = false;
            for(int i = 0; stop==false && i<patientsAL.size(); i++){
                Patient curr = patientsAL.get(i);
                if( test ){
                    System.out.println("curr: " + curr._name + ", " + curr._level);
                }
                if( incoming._level > curr._level ){
                    stop = true;
                    patientsAL.add(i, incoming);
                }

                if( incoming._level == curr._level ){
                    int incomingIndex = patientsOrderOfArrival.indexOf(incoming._name);
                    int currIndex = patientsOrderOfArrival.indexOf(curr._name);
                    if( test ){
                        System.out.println("incomingIndex = " + incomingIndex + ", currIndex = " + currIndex);
                    }
                    if( incomingIndex < currIndex ){
                        stop = true;
                        patientsAL.add(i, incoming);
                    }
                }
            }
            if( stop==false ){
                patientsAL.add(incoming);
                patientsHMap.put(incoming._name, incoming._level);
            }
        }
    }

    void ArriveAtHospital(String patientName, int emergencyLvl) {
        if( test ){
            System.out.println("To add: " + patientName + ", " + emergencyLvl);
        }
        Patient incoming = new Patient(patientName, emergencyLvl);
        storesPatient(incoming);
        patientsHMap.put(patientName, emergencyLvl);
        patientsOrderOfArrival.add(patientName);
        if( test ){
            System.out.println("After arrival@hospital: ");
            print();
        }
    }

    /*
     * Removes patient from queue
     * Precon: User wants to update or remove a patient
     * Postcon: Patient is removed from both Arraylist
     */
    private void removesPatient(String name){
        boolean stop = false;
        for(int i = 0; stop==false && i<patientsAL.size(); i++){
            Patient curr = patientsAL.get(i);
            if( test ){
                System.out.println("curr: " + curr._name);
            }
            if( name.equals(curr._name) ){
                if( test ){
                    System.out.println("Found!");
                }
                stop = true;
                patientsAL.remove(i);
            }
        }
    }

    void Treat(String patientName){
        if( test ){
            System.out.println("To treat: " + patientName);
            System.out.println("Before removal: ");
            print();
        }
        removesPatient(patientName);
        patientsHMap.remove(patientName);
        patientsOrderOfArrival.remove(patientName);
        if( test ){
            System.out.println("After removal: ");
            print();
        }
    }

    String Query() {
        if( patientsAL.isEmpty() ){
            return "The emergency suite is empty";
        }
        else{
            return ((patientsAL.get(0))._name);
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
