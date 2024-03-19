// Copy paste this Java Template and save it as "EmergencyRoom.java"
import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: SHEIKH UMAR
// write list of collaborators here:
// year 2018 hash code: FxYTABbg8BUwrG7T76qY (do NOT delete this line)

class EmergencyRoom {
    private ArrayList <Patient> patientsList = new ArrayList <> ();
    private boolean isTest = false;
    private HashMap <String, Integer> patientsMap = new HashMap <> ();

    // Display patients in order
    // Precon: isTest  ==  true
    // Postcon: nil
    private void displaysPatientsListAndMap() {
        int count = 1;
        System.out.println("patientsList: ");
        for (int i = 0; i<patientsList.size(); i++) {
            System.out.print("Patient " + count++ + ": ");
            Patient patient = patientsList.get(i);
            System.out.println(patient.getsName() + " " + patient.getsLevel());
        }
        System.out.println("patientsMap: " + patientsMap);
        System.out.println();
    }

    void updatesEmergencyLevel(String patientName, int incEmergencylevel) {
        int originalValue = (patientsMap.get(patientName)).intValue();
        int updatedValue = originalValue + incEmergencylevel;
        if (updatedValue > 100) {
            updatedValue = 100;
        }
        if (isTest) {
            System.out.println("To update: " + patientName);
            System.out.println("originalValue = " + originalValue + ", updatedValue = " + updatedValue);
            System.out.println("Before update, patientsMap: " + patientsMap);
        }
        patientsMap.put(patientName, updatedValue);
        if (isTest) {
            System.out.println("After update, patientsMap: " + patientsMap);
        }
        removesPatient(patientName);
        Patient updated = new Patient(patientName, updatedValue);
        if (isTest) {
            System.out.println("To add updated: " + patientName + ", " + updatedValue);
        }
        storesPatient(updated);
    }

    /* Put patient into queue
     * Precon: Patient has arrived at hospital
     * Postcon: Patient is in correct position of queue
     */
    private void storesPatient(Patient incomingPatient) {
        if (patientsList.isEmpty()) {
            patientsList.add(incomingPatient);
            patientsMap.put(incomingPatient.getsName(), incomingPatient.getsLevel());
        } else {
            boolean isStop = false;
            for (int i = 0; !isStop && i < patientsList.size(); i++) {
                Patient currentPatient = patientsList.get(i);
                if (isTest) {
                    System.out.println("currentPatient: " + currentPatient.getsName() + ", " + currentPatient.getsLevel());
                }
                if (incomingPatient.getsLevel() > currentPatient.getsLevel() 
                    || (incomingPatient.getsLevel() == currentPatient.getsLevel() && patientsMap.containsKey(incomingPatient.getsName()))) {
                    isStop = true;
                    patientsList.add(i, incomingPatient);
                }
            }
            if (!isStop) {
                patientsList.add(incomingPatient);
                patientsMap.put(incomingPatient.getsName(), incomingPatient.getsLevel());
            }
        }

        if (isTest) {
            System.out.println("After adding: ");
            displaysPatientsListAndMap();
        }
    }

    void arrivesAtHospital(String patientName, int emergencylevel) {
        if (isTest) {
            System.out.println("To add: " + patientName + ", " + emergencylevel);
        }
        Patient incomingPatient = new Patient(patientName, emergencylevel);
        storesPatient(incomingPatient);
        patientsMap.put(patientName, emergencylevel);
    }

    /*
     * Removes patient from queue
     * Precon: User wants to update or remove a patient
     * Postcon: Patient is removed from both Arraylist
     */
    private void removesPatient(String name) {
        for (int i = 0; i < patientsList.size(); i++) {
            Patient currentPatient = patientsList.get(i);
            if (isTest) {
                System.out.println("currentPatient: " + currentPatient.getsName());
            }
            if (name.equals(currentPatient.getsName())) {
                if (isTest) {
                    System.out.println("Found!");
                }
                patientsList.remove(i);
                break;
            }
        }
    }

    void treatsPatient(String patientName) {
        if (isTest) {
            System.out.println("To treatsPatient: " + patientName);
            System.out.println("Before removal: ");
            displaysPatientsListAndMap();
        }
        removesPatient(patientName);
        patientsMap.remove(patientName);
        if (isTest) {
            System.out.println("After removal: ");
            displaysPatientsListAndMap();
        }
    }

    String queriesFirstPatient() {
        if (patientsList.isEmpty()) {
            return "The emergency suite is empty";
        }
        else {
            return ((patientsList.get(0)).getsName());
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

class Patient {
    private int level;
    private String name;

    public Patient(String name, int level) {
        this.level = level;
        this.name = name;
    }

    public int getsLevel() {
        return this.level;
    }

    public String getsName() {
        return this.name;
    }
}
