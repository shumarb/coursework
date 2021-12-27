// Copy paste this Java Template and save it as "PatientNames.java"
import java.util.*;
import java.io.*;

// write your matric number here: A0149874L
// write your name here: SHEIKH UMAR
// write list of collaborators here:
// year 2018 hash code: edyFpB4rcbU64QHhV8S9 (do NOT delete this line)

class PatientNames {
    private boolean test = false;
    private TreeSet <String> patientsMale = new TreeSet <String> ();
    private TreeSet <String> patientsFemale = new TreeSet <String> ();
    private TreeMap <String, Integer> patientsInfo = new TreeMap <String, Integer> ();    

    /*
     * Displays treesets
     * Precon: test==true
     * Postcon: Nil
     */
    private void displays(){
        System.out.println("patientsInfo: " + patientsInfo);
        System.out.println("patientsMale: " + patientsMale);
        System.out.println("patientsFemale: " + patientsFemale);
        System.out.println();
    }

    void AddPatient(String patientName, int gender) {
        patientsInfo.put(patientName, gender);
        if( gender==1 ){
            patientsMale.add(patientName);
        }
        else{
            patientsFemale.add(patientName);
        }

        if( test ){
            displays();
        }
    }

    void RemovePatient(String patientName) {
        int gender = (patientsInfo.get(patientName)).intValue();
        patientsInfo.remove(patientName);
        if( gender==1 ){
            patientsMale.remove(patientName);
        }
        else{
            patientsFemale.remove(patientName);
        }

        if( test ){
            displays();
        }
    }

    int Query(String START, String END, int gender) {
        int ans = 0;
        if( gender==1 ){
            SortedSet <String> malesQuery = patientsMale.subSet(START, true, END, false);
            if( test ){
                System.out.println("malesQuery: " + malesQuery);
            }
            ans = malesQuery.size();
        }
        else if( gender==2 ){
            SortedSet <String> femalesQuery = patientsFemale.subSet(START, true, END, false);
            if( test ){
                System.out.println("femalesQuery: " + femalesQuery);
            }
            ans = femalesQuery.size();
        }
        else{
            SortedSet <String> malesQuery = patientsMale.subSet(START, true, END, false);
            SortedSet <String> femalesQuery = patientsFemale.subSet(START, true, END, false);
            if( test ){
                System.out.println("malesQuery: " + malesQuery);
                System.out.println("femalesQuery: " + femalesQuery);
            }
            ans = malesQuery.size() + femalesQuery.size();
        }

        if( test ){
            System.out.println("ans = " + ans);
        }

        return ans;
    }


    void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            if (command == 0) // end of input
                break;
            else if (command == 1) // AddPatient
                AddPatient(st.nextToken(), Integer.parseInt(st.nextToken()));
            else if (command == 2) // RemovePatient
                RemovePatient(st.nextToken());
            else // if (command == 3) // Query
                pr.println(Query(st.nextToken(), // START
                            st.nextToken(), // END
                            Integer.parseInt(st.nextToken()))); // GENDER
        }
        pr.close();
    }

    public static void main(String[] args) throws Exception{
        PatientNames ps2 = new PatientNames();
        ps2.run();
    }
}
