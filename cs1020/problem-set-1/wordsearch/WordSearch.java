/*
 * Name       : SHEIKH UMAR 
 * Matric No. : A0149874L
 * Plab Acct. : e0014778
 */

// Program computes the number of times a word appears in a puzzle

import java.util.*;

public class WordSearch{
    private boolean test = false;
    private int count = 0, N;
    private String word, wordRev = "";
    private Scanner sc = new Scanner(System.in);

    // Display number of times word is found in grid.
    // Precon: Word has been search in all possible directions in grid.
    // Postcon: Nil.
    private void print(){
        System.out.println(count);
    }

    // Check if word formed has word and/or wordRev.
    // Precon: Word formed's length is >= word's length
    // Poston: Count increases after word formed from grid is checked
    // with word and/or wordRev.
    private void check(String form){
        int start = 0;

        while( (form.length()-start)>=word.length() ){
            String form2 = "";
            int end = start+word.length();

            for(int i = start; i<end; i++){
                form2+=form.charAt(i);
            }
            if( test ){
                System.out.println("form2 = " + form2);
            }
            if( form2.contains(word) || form2.contains(wordRev) ){
                count+=1;
            }
            start+=1;
        }
    }

    // Read in N and characters
    // Precon: User has not entered word and N and characters.
    // Postcon: User has entered word and N and characters.
    private void read(){
        word = sc.next();
        if( test ){
            System.out.println("Word = " + word);
        }
        for(int i = word.length()-1; i>=0; i--){
            wordRev+=word.charAt(i);
        }
        if( test ){
            System.out.println("WordRev = " + wordRev);
        }
        //System.out.println();
        N = sc.nextInt();
        char[][] grid = new char[N][N];
        if( test ){
            System.out.println("N = " + N);
        }
        readGrid(grid);
    }

    // Read in characters as strings.
    // Precon: Grid cells are null.
    // Postcon: Grid cells contain a character (entered as a string)
    // entered from user.
    private void readGrid(char[][] grid){
        for(int i = 0; i<N; i++){
            String readWord = sc.next();
            if( test ){
                System.out.println("readWord = " + readWord);
            }
            for(int j = 0; j<N; j++){
                grid[i][j] = readWord.charAt(j);
            }
        }
        if( test ){
            printGrid(grid);
        }
        checkRows(grid);
        checkCols(grid);
        checkDiag1(grid);
        checkDiag2(grid);
        print();
    }

    // Check for appearance of word & worfRev in north-east diagonals.
    // Precon: Word & wordRev have been checked in rows, cols, and
    // north-west diagonals of grid.
    // Postcon: Count has increased.
    private void checkDiag2(char[][] grid){
        int i = 1, k = 1, j = 0;
        while(i<N){
            String form = "";
            while(i>=0 && j<N){
                form+=grid[i--][j++];
            }
            if( test ){
                System.out.println("form = " + form);
            }
            if( form.length()>=word.length() ){
                check(form);
            }
            k+=1;
            i=k;
            j=0;
        }

        i = N-1;
        j = 1;
        k = 1;

        while(j<(N-1)){
            String form = "";
            while(i>=0 && j<N){
                form+=grid[i--][j++];
            }
            if( test ){
                System.out.println("form = " + form);
            }
            if( form.length()>=word.length() ){
                check(form);
            }
            k+=1;
            j=k;
            i=N-1;
        }
    }

    // Check for appearance of word & wordRev in north-west diagonals.
    // Precon: Word & wordRev have been checked in all rows & cols of grid.
    // Postcon: Count has increased.
    private void checkDiag1(char[][] grid){
        int i=N-1, j=1, k=1;

        while(j<N){
            String form = "";
            while(i>=0 && j>=0){
                form+=grid[i][j];
                i-=1;
                j-=1;
            }
            if( test ){
                System.out.println("form = " + form);
            }
            if(form.length()>=word.length()){
                check(form);
            }
            i=N-1;
            k+=1;
            j=k;
        }

        i=N-2;
        k=N-2;
        j=N-1;
        if( test ){
            System.out.println("i = " + i + ", k = " + k + ", j = " + j);
        }
        while(i>0){
            String form = "";
            while(i>=0 && j>=0){
                form+=grid[i--][j--];
            }
            if( test ){
                System.out.println("form = " + form);
            }
            if(form.length()>=word.length()){
                check(form);
            }
            k-=1;
            i=k;
            j=N-1;
        }
    }

    // Check if word and/or wordRevis in rows
    // Precon: Grid contains all characters derived from string that
    // user entered.
    // Postcon: Count has increased
    private void checkRows(char[][] grid){
        for(int i = 0; i<N; i++){
            String form = "";
            for(int j = 0; j<N; j++){
                form+=grid[i][j];
            }
            if( test ){
                System.out.println("form = " + form);
            }
            if(form.length()>=word.length()){
                check(form);
            }
        }
    }

    // Check if word and/or wordRevis in cols.
    // Precon: Grid contains all characters derived from string that
    // user entered.
    // Postcon: Count has increased
    private void checkCols(char[][] grid){
        for(int i = 0; i<N; i++){
            String form = "";
            for(int j = 0; j<N; j++){
                form+=grid[j][i];
            }
            if( test ){
                System.out.println("form = " + form);
            }
            if(form.length()>=word.length()){
                check(form);
            }
        }
    }

    // Display grid.
    // Precon: test==true.
    // Postcon: Nil.
    private void printGrid(char[][] grid){
        System.out.println();
        System.out.println("Grid: ");
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private void run(){
        read();
    }

    public static void main(String[] args){
        WordSearch obj = new WordSearch();
        obj.run();
    }
}
