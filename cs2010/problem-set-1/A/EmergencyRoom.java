// Copy paste this Java Template and save it as "EmergencyRoom.java"
import java.util.*;
import java.io.*;

class Patient implements Comparable <Patient> {
    private String _name;
    private int _level;
    private int _position;

    public Patient(String name, int level, int position) {
        this._name = name;
        this._level = level;
        this._position = position;
    }   

    public String getName() {
        return _name;
    }

    public int getLevel() {
        return _level;
    }

    public int getPosition( ){
        return _position;
    }

    public int compareTo(Patient incoming) {
        if(incoming._level < this._level) {
            return -1;
        }
        else if(incoming._level > this._level) {
            return 1;
        }
        else {
            if(incoming._position < this._position) {
                return 1;
            }
            else if(incoming._position > this._position) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}

public class EmergencyRoom {
    private boolean isTest = true;
    private TreeMap <String, Integer> patientsLevel = new TreeMap <String, Integer>();
    private TreeMap <String, Integer> patientsPosition = new TreeMap <String, Integer> ();
    private TreeSet <Patient> patientsTree = new TreeSet <Patient>();
    private int count = 1;

    /*
     * Displays information in data structures
     * Precon: test==true.
     * Postcon: Nil.
     */
    private void displaysInformation() {
        System.out.println("patientsLevel: " + patientsLevel);
        System.out.println("patientsPosition: " + patientsPosition);
        System.out.println("patientsTree: ");
        int count = 1;
        for(Patient curr: patientsTree) {
            System.out.print("Patient " + count++ + ": ");
            System.out.println(curr.getName() + ", " + curr.getLevel() + ", " + curr.getPosition());
        }
        System.out.println();
    }

    /*
     * Creates patient.
     * Precon: User entered option 0.
     * Postcon: Patient's information is stored in the hashmaps.
     */
    private Patient createsPatient(String patientName, int emergencyLvl) {
        patientsLevel.put(patientName, emergencyLvl);
        patientsPosition.put(patientName, count);
        Patient incoming = new Patient(patientName, emergencyLvl, count++);
        return incoming;
    }

    /* 
     * Stores patient into treeset.
     * Precon: Patient's info is stored in 2 treemaps
     * Postcon: Patient is added into treeset
     */
    private void storesPatient(Patient incoming) {
        patientsTree.add(incoming);
    }

    void ArriveAtHospital(String patientName, int emergencyLvl) {
        Patient incoming = createsPatient(patientName, emergencyLvl);
        storesPatient(incoming);
        if(isTest) {
            displaysInformation();
        }
    }

    /*
     * Removes patient from treeset
     * Precon: User entered option 1 or 2
     * Postcon: Patient is removed from treeset
     */
    private void removesPatient(Patient toRemove) {
        if(isTest) {
            System.out.print("To remove: ");
            System.out.println(toRemove.getName() + ", " + toRemove.getLevel() + ", " + toRemove.getPosition());
            System.out.println("Before removal: ");
            displaysInformation();
        }
        patientsTree.remove(toRemove);
        patientsPosition.remove(toRemove.getName());
        patientsLevel.remove(toRemove.getName());
        if(isTest) {
            System.out.println("After removal: ");
            displaysInformation();
        }
    }

    /* Forms patient to remove
     * Precon: User entered option 1
     * Postcon: Patient that user entered has been removed
     */
    private Patient formsToRemove(String patientName ){
        int position = patientsPosition.get(patientName);
        int level = patientsLevel.get(patientName);
        Patient toRemove = new Patient(patientName, level, position);
        return toRemove;
    }

    void Treat(String patientName) {
        Patient toRemove = formsToRemove(patientName);        
        removesPatient(toRemove);
    }

    /*
     * Updates patient's level
     * Precon: User entered option 2
     * Postcon: Patient level has been updated
     */
    private int updatesLevel(String patientName, int incEmergencyLvl) {
        int updatedVal = incEmergencyLvl + (patientsLevel.get(patientName)).intValue();
        return updatedVal;
    }

    /*
     * Removes patient from treeset.
     * Precon: User entered option 2
     * Postcon: Patient has been removed from treeset
     */
    private void removesPatientV2(Patient toUpdate) {
        if(isTest) {
            System.out.print("To remove: ");
            System.out.println(toUpdate.getName() + ", " + toUpdate.getLevel() + ", " + toUpdate.getPosition());
            System.out.println("Before removal: ");
            displaysInformation();
        }
        patientsTree.remove(toUpdate);
        if(isTest) {
            System.out.println("After removal: ");
            displaysInformation();
        }
    }

    /*
     * Stores patient into treeset.
     * Precon: User entered option 1.
     * Postcon: Upated patient is added into treeset
     */
    private void storesPatientV2(String patientName, int updatedVal, int originalPosition) {
        Patient updated = new Patient(patientName, updatedVal, originalPosition);
        patientsTree.add(updated);
        if(isTest) {
            System.out.println("After update: ");
            displaysInformation();
        }
    }

    void UpdateEmergencyLvl(String patientName, int incEmergencyLvl) {
        int updatedVal = updatesLevel(patientName, incEmergencyLvl);
        int originalPosition = patientsPosition.get(patientName);
        if(isTest) {
            System.out.println("UpdatedVal = " + updatedVal + ", originalPosition = " + originalPosition);
        }
        Patient toUpdate = formsToRemove(patientName);
        removesPatientV2(toUpdate);
        patientsLevel.put(patientName, updatedVal);
        storesPatientV2(patientName, updatedVal, originalPosition);
    }

    String Query() {
        if(patientsTree.isEmpty()) {
            return "The emergency suite is empty";
        }
        else {
            Patient highest = patientsTree.first();
            if(isTest) {
                System.out.print("Highest: ");
                System.out.println(highest.getName() + ", " + highest.getLevel() + ", " + highest.getPosition());
            }
            return highest.getName();
        }
    }

    void run() throws Exception {
        // do not alter this method

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int numCMD = Integer.parseInt(br.readLine()); // note that numCMD >= N
        while (numCMD-- >0 ) {
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

    public static void main(String[] args) throws Exception {
        // do not alter this method
        EmergencyRoom ps1 = new EmergencyRoom();
        ps1.run();
    }
}

