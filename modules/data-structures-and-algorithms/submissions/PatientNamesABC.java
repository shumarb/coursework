// Copy paste this Java Template and save it as "PatientNamesABC.java"
import java.io.*;
import java.util.*;

// write your matric number here: A0149874L
// write your name here: SHEIKH UMAR
// write list of collaborators here:
// year 2018 hash code: edyFpB4rcbU64QHhV8S9 (do NOT delete this line)

class PatientNames {
    private boolean isTest = false;
    private TreeMap <String, Integer> patientsInfoMap = new TreeMap <> ();
    private TreeSet <String> patientsFemaleSet = new TreeSet <> ();
    private TreeSet <String> patientsMaleSet = new TreeSet <> ();

    /*
     * Displays treemap and treesets
     * Precon: isTest == true
     * Postcon: Nil
     */
    private void displaysMapAndSets() {
        System.out.println("patientsInfoMap: " + patientsInfoMap);
        System.out.println("patientsMaleSet: " + patientsMaleSet);
        System.out.println("patientsFemaleSet: " + patientsFemaleSet);
        System.out.println();
    }

    void addsPatient(String patientName, int genderType) {
        patientsInfoMap.put(patientName, genderType);
        if (genderType == 1) {
            patientsMaleSet.add(patientName);
        } else {
            patientsFemaleSet.add(patientName);
        }

        if (isTest) {
            displaysMapAndSets();
        }
    }

    void removesPatient(String patientName) {
        int genderType = (patientsInfoMap.get(patientName)).intValue();
        patientsInfoMap.remove(patientName);
        if (genderType == 1) {
            patientsMaleSet.remove(patientName);
        } else {
            patientsFemaleSet.remove(patientName);
        }

        if (isTest) {
            displaysMapAndSets();
        }
    }

    int Query(String startName, String endName, int genderType) {
        if (genderType == 1) {
            SortedSet <String> malesQuerySet = patientsMaleSet.subSet(startName, true, endName, false);
            if (isTest) {
                System.out.println("malesQuerySet: " + malesQuerySet);
            }
            return malesQuerySet.size();
        } else if (genderType == 2) {
            SortedSet <String> femalesQuerySet = patientsFemaleSet.subSet(startName, true, endName, false);
            if (isTest) {
                System.out.println("femalesQuerySet: " + femalesQuerySet);
            }
            return femalesQuerySet.size();
        } else {
            SortedSet <String> malesQuerySet = patientsMaleSet.subSet(startName, true, endName, false);
            SortedSet <String> femalesQuerySet = patientsFemaleSet.subSet(startName, true, endName, false);
            if (isTest) {
                System.out.println("malesQuerySet: " + malesQuerySet);
                System.out.println("femalesQuerySet: " + femalesQuerySet);
            }
            return malesQuerySet.size() + femalesQuerySet.size();
        }
    }

    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            if (command  ==  0) // endName of input
                break;
            else if (command  ==  1) // addsPatient
                addsPatient(st.nextToken(), Integer.parseInt(st.nextToken()));
            else if (command  ==  2) // removesPatient
                removesPatient(st.nextToken());
            else // if (command  ==  3) // Query
                pr.println(Query(st.nextToken(), // startName
                            st.nextToken(), // endName
                            Integer.parseInt(st.nextToken()))); // genderType
        }
        pr.close();
    }

    public static void main(String[] args) throws Exception{
        PatientNames ps2 = new PatientNames();
        ps2.run();
    }
}
