// Copy paste this Java Template and save it as "EmergencyRoom.java"
import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: SHEIKH UMAR
// write list of collaborators here:
// year 2018 hash code: FxYTABbg8BUwrG7T76qY (do NOT delete this line)

public class EmergencyRoom {
    private boolean isTest = false;
    private int count = 1;
    private TreeMap <String, Integer> patientsLevelMap = new TreeMap <>();
    private TreeMap <String, Integer> patientsPositionMap = new TreeMap <> ();
    private TreeSet <Patient> patientsTree = new TreeSet <> ();

    /*
     * Displays information in data structures
     * Precon: isTest == true.
     * Postcon: Nil.
     */
    private void displaysInformation() {
        System.out.println("patientsLevelMap: " + patientsLevelMap);
        System.out.println("patientsPositionMap: " + patientsPositionMap);
        System.out.println("patientsTree: ");
        int numPatient = 1;
        for (Patient curr: patientsTree) {
            System.out.print("Patient " + numPatient++ + ": ");
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
        patientsLevelMap.put(patientName, emergencyLvl);
        patientsPositionMap.put(patientName, count);
        return new Patient(patientName, emergencyLvl, count++);
    }

    /* 
     * Stores patient into treeset.
     * Precon: Patient's info is stored in 2 treemaps
     * Postcon: Patient is added into treeset
     */
    private void storesPatient(Patient incomingPatient) {
        patientsTree.add(incomingPatient);
    }

    void arrivesAtHospital(String patientName, int emergencyLvl) {
        Patient incomingPatient = createsPatient(patientName, emergencyLvl);
        storesPatient(incomingPatient);
        if (isTest) {
            displaysInformation();
        }
    }

    /*
     * Removes patient from treeset
     * Precon: User entered option 1 or 2
     * Postcon: Patient is removed from treeset
     */
    private void removesPatient(Patient patientToRemove) {
        if (isTest) {
            System.out.print("To remove: ");
            System.out.println(patientToRemove.getName() + ", " + patientToRemove.getLevel() + ", " + patientToRemove.getPosition());
            System.out.println("Before removal: ");
            displaysInformation();
        }
        patientsTree.remove(patientToRemove);
        patientsPositionMap.remove(patientToRemove.getName());
        patientsLevelMap.remove(patientToRemove.getName());
        if (isTest) {
            System.out.println("After removal: ");
            displaysInformation();
        }
    }

    /* Forms patient to remove
     * Precon: User entered option 1
     * Postcon: Patient that user entered has been removed
     */
    private Patient formsToRemove(String patientName) {
        int position = patientsPositionMap.get(patientName);
        int level = patientsLevelMap.get(patientName);
        return new Patient(patientName, level, position);
    }

    void treatsPatient(String patientName) {
        Patient toRemove = formsToRemove(patientName);        
        removesPatient(toRemove);
    }

    /*
     * Updates patient's level
     * Precon: User entered option 2
     * Postcon: Patient level has been updated
     */
    private int updatesLevel(String patientName, int emergencyLevel) {
        return emergencyLevel + (patientsLevelMap.get(patientName)).intValue();
    }

    /*
     * Removes patient from treeset.
     * Precon: User entered option 2
     * Postcon: Patient has been removed from treeset
     */
    private void removesPatientV2(Patient patientToUpdate) {
        if (isTest) {
            System.out.print("To remove: ");
            System.out.println(patientToUpdate.getName() + ", " + patientToUpdate.getLevel() + ", " + patientToUpdate.getPosition());
            System.out.println("Before removal: ");
            displaysInformation();
        }
        patientsTree.remove(patientToUpdate);
        if (isTest) {
            System.out.println("After removal: ");
            displaysInformation();
        }
    }

    /*
     * Stores patient into treeset.
     * Precon: User entered option 1.
     * Postcon: Upated patient is added into treeset
     */
    private void storesPatientV2(String patientName, int updatedValue, int originalPosition) {
        Patient updated = new Patient(patientName, updatedValue, originalPosition);
        patientsTree.add(updated);
        if (isTest) {
            System.out.println("After update: ");
            displaysInformation();
        }
    }

    void updatesEmergencyLevel(String patientName, int emergencyLevel) {
        int updatedValue = updatesLevel(patientName, emergencyLevel);
        int originalPosition = patientsPositionMap.get(patientName);
        if (isTest) {
            System.out.println("updatedValue = " + updatedValue + ", originalPosition = " + originalPosition);
        }
        Patient patientToUpdate = formsToRemove(patientName);
        removesPatientV2(patientToUpdate);
        patientsLevelMap.put(patientName, updatedValue);
        storesPatientV2(patientName, updatedValue, originalPosition);
    }

    String queriesFirstPatient() {
        if (patientsTree.isEmpty()) {
            return "The emergency suite is empty";
        } else {
            Patient highest = patientsTree.first();
            if (isTest) {
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
        while (numCMD-- >0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            switch (command) {
                case 0: arrivesAtHospital(st.nextToken(), Integer.parseInt(st.nextToken())); break;
                case 1: updatesEmergencyLevel(st.nextToken(), Integer.parseInt(st.nextToken())); break;
                case 2: treatsPatient(st.nextToken()); break;
                case 3: pr.println(queriesFirstPatient()); break;
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

class Patient implements Comparable <Patient> {
    private int level;
    private int position;
    private String name;

    public Patient(String name, int level, int position) {
        this.level = level;
        this.name = name;
        this.position = position;
    }   

    public int compareTo(Patient incomingPatient) {
        if (incomingPatient.level < this.level) {
            return -1;
        }
        else if (incomingPatient.level > this.level) {
            return 1;
        }
        else {
            if (incomingPatient.position < this.position) {
                return 1;
            }
            else if (incomingPatient.position > this.position) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }

    public int getLevel() {
        return this.level;
    }

    public int getPosition() {
        return this.position;
    }

    public String getName() {
        return this.name;
    }
}
