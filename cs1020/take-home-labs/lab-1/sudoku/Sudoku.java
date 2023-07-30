/*
 * Name		: SHEIKH UMAR
 * Matric No.		: A0149874L
 * Plab Account	: pe12
 */

import java.util.*;

public class Sudoku {
    private Scanner sc = new Scanner(System.in);
    private boolean isTest = false, isProceed = true;
    private int size, N;

    // Read in all entries of matrix
    // Precon: Matrix is filled with 0's only, and user has not entered
    // values of matrix
    // Postcon: Matrix contains all entries from user
    private void read(int[][]mat, int size){
        if(isTest){
            System.out.println("Enter entries: ");
        }
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                mat[x][y] = sc.nextInt();
            }
        }

        // Display matrix
        if(isTest){
            System.out.println("matrix after reading in values ");
            for(int x = 0; x < size; x++){
                for(int y = 0; y < size; y++){
                    System.out.print(mat[x][y] + " ");
                }
                System.out.println();
            }
        }
    }

    // Precon: Matrix has valid row, columns, and submatrices
    // Postcon: NIL
    private void printValid(){
        System.out.println("VALID");
    }

    // Precon: Matrix has an invalid row/column/submatrices
    // Postcon: NIL
    private void printInvalid(){
        System.out.println("INVALID");
    }

    // Check if row entries have no duplicates and are within 1 and
    // size^2 inclusive
    // Precon: Row array is row entries of the matrix
    // Postcon: Return true if row entries have no duplicates and are within 1 and
    // size^2 inclusive
    private boolean check(int[] row, int size){
        int[] dig = new int[size];
        int elem;
        if(isTest){
            System.out.print("dig array: ");
            for(int f = 0; f < size; f++){
                System.out.print(dig[f] + " ");
            }
            System.out.println();
        }
        // Obtain entry in row, increase dig element representing this
        // element to 1, check if this element is >1. If yes, return
        // false
        for(int e = 0; e < size; e++){
            elem = row[e];
            dig[elem - 1] += 1;

            // Valid only if no duplicates and entry is <=size
            if(dig[elem - 1] > 1 || elem <= 0 || elem > size){
                return false;
            }
        }
        return true; // Entries in row are valid
    }

    // Form a 1D array consisting of row entries from mat.
    // Send rows to check method to check if it is valid.
    // Precon: Matrix has all entries from user
    // Postcon: Row entries are valid
    private boolean passRow(int[][]mat, int size){
        boolean isProceed = true;

        for(int a = 0; a < size && isProceed == true; a++){
            int c = 0;
            int[] row = new int[size];
            for(int b = 0; b < size && isProceed == true; b++){
                row[c] = mat[a][b];
                c += 1;
            }

            if(isTest){
                System.out.print("row: ");
                for(int d = 0; d < size; d++){
                    System.out.print(row[d] + " ");
                }
                System.out.println();
            }

            // Send row to check method, which returns true or false
            isProceed = check(row,size);
        }
        return isProceed;
    }

    // Form a 1D array consisting of column entries from mat.
    // Send columns to check method to check if it is valid.
    // Precon: Row entries are valid
    // Postcon: Column entries are valid
    private boolean passCol(int[][]mat, int size){
        boolean isProceed = true;

        for(int a = 0; a < size && isProceed == true; a++){
            int c = 0;
            int[] row = new int[size];
            for( int b = 0; b < size && isProceed == true; b++){
                row[c] = mat[b][a];
                c += 1;
            }

            if(isTest){
                System.out.print("row: ");
                for(int d = 0; d < size; d++){
                    System.out.print(row[d] + " ");
                }
                System.out.println();
            }

            // Send row to check method, which returns true or false
            isProceed = check(row, size);
        }
        return isProceed;
    }

    // Matrix checks submatrices and returns true or false.
    // If false: Once of the submatrices is invalid, hence matrix is
    // invalid
    // Precon: Matrix has valid row and column entries
    // Postcon: Matrix has valid submatrices
    private boolean passSubMat(int[][] mat,int size){
        boolean isProceed = true;
        boolean isStop = false;

        // First 2 loops are based to jump from submatrix in a row and
        // col to the next row and col by N
        for(int a = 0; isStop == false && a < size; a += N){
            int start = a, endStart = start + N; // Condition to stop inner
            for(int b = 0; b < size && isStop == false; b += N){
                int end = b, endEnd = end + N;

                isProceed = formSub(mat, start, endStart, end, endEnd);
                if(isProceed == false){
                    return false;
                }
            }
        }
        return true; // Submatrices are valid
    }

    // Form submatrices, check if it is valid, return true if valid
    // Precon: starting and ending index received
    // Postcon: nil
    private boolean formSub(int[][]mat, int start, int startEnd, int end, int endEnd){
        int[][] sub = new int[N][N];
        boolean isStop = false;
        int e = 0, f = 0;

        // Form submatrix, check submatrix
        for(int i = start; i < startEnd; i++){
            f = 0;
            for(int j = end; j < endEnd; j++){
                sub[e][f] = mat[i][j];
                f += 1; // Go to next column;
            }
            e += 1;
        }
        
        // Display submatrix
        if (isTest){
            dispSub(sub);
        }
        
        isStop = checkSub(sub);
        if(isStop == false){
            return false;
        }

        return true; // valid submatrix
    }
    // Check if entries of submatrix has no duplicates and is within 1
    // to N^2.
    // Precon: Argument is submatrix
    // Postcon: nil
    private boolean checkSub(int[][] sub){
        int[] dig = new int[size]; // Digits representing 1 to N^2
        int elem;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                elem = sub[i][j];

                // Check if elem is >N^2. If yes, return false
                if(elem > (N * N) || elem <= 0){
                    return false;
                }

                // elem between 1 to N
                dig[elem - 1] += 1;
                // if value of element in dig is >1, there is a
                // duplicate, so return false
                if(dig[elem - 1] > 1){
                    return false;
                }
            }
        }
        return true; // Valid submatrix
    }

    // Display submatrix found
    // Precon: Submatrix is formed and of size N
    // Postcon: nil
    private void dispSub(int[][] sub){
        System.out.println("Submat: ");
        for(int h = 0; h < N; h++){
            for(int p = 0; p < N; p++){
                System.out.print(sub[h][p] + " ");
            }
            System.out.println();
        }
    }

    private void run(){
        N = sc.nextInt();
        size = N * N;
        if(isTest){
            System.out.print("N = " + N);
            System.out.println(", row = " + size + ", col = " + size);
        }

        int[][]mat = new int[size][size];
        if(isTest){
            System.out.println("matrix formed: ");
            for(int x = 0; x < size; x++){
                for(int y = 0; y < size; y++){
                    System.out.print(mat[x][y] + " ");
                }
                System.out.println();
            }
        }

        // Pass to read method, read in entries of matrix
        read(mat,size);
        isProceed = passRow(mat, size);
        if(isProceed == false){
            printInvalid();
        }
        else{

            // Check column entries if they are valid.
            isProceed  = passCol(mat, size);
            if(isProceed == false){
                printInvalid();
            }
            else{
                isProceed = passSubMat(mat, size);
                if(isProceed == false){
                    printInvalid();
                }
                else{
                    printValid();
                }
            }
        }
    }

    public static void main(String[] args) {
        Sudoku mysudoku = new Sudoku();
        mysudoku.run();
    }
}

