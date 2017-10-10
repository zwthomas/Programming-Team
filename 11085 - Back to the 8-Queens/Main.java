/*
 * Zachary Thomas
 * 10/10/2017
 * CSM 3070
 * Solution to UVa Judge problem 11085 - Back to the 8-Queens
 */

import java.util.Scanner;

public class Main {

    private static final int DIM = 8;
    private static int MIN_MOVES = 10;
    private static final Scanner CIN = new Scanner(System.in);

    /**
     * Reads in the starting positions of each piece in a test case.
     * 
     * @return 2D array with 1's in the locations of the Queens 
     */
    private static int[][] readInTestCase() {
        int[][] positions = new int[DIM][DIM];
        for (int col = 0; col < DIM; col++) {
            positions[CIN.nextInt() - 1][col] = 1;
        }

        return positions;
    }

    /**
     * Prints the board for testing purposes.
     * 
     * @param b board to be printed
     */
    private static void displayBoard(int[][] b) {
        for (int row = 0; row < DIM; row++) {
            for (int col = 0; col < DIM; col++) {
                System.out.print(b[row][col] + " ");
            }
            System.out.println();
        }
    }
    
    /**
     * Wrapper function for the recursive search on the board. 
     * 
     * @param b board to be searched 
     */
    private static void runTest(int[][] b) {
        search(b, 0, 0);
    }
    
    /**
     * Attempts to place all of the pieces in non-attacking positions.
     * 
     * @param b The board the pieces are being placed.
     * @param col The current column we are working on.
     * @param moveCount The number of moves that have been made.
     */
    private static void search(int[][] b, int col, int moveCount) {
        // Base case column is off the board
        if (col == DIM) {
            // Update min
            if (moveCount < MIN_MOVES) MIN_MOVES = moveCount;
            
            return;
        }
        
        // Save starting position of the piece
        int piecePosition = findPiece(b, col);
        
        // Go trough every row in the column
        for (int row = 0; row < DIM; row++) {
            // If we are able to place a piece here
            if(validPosition(b, row, col)) {
                // If the piece is already in this position 
                if (row == piecePosition) {
                    // Move to next column and don't change move count 
                    search(b, col + 1, moveCount);
                // A piece needs to be moved
                } else {
                    // Move the piece
                    b[piecePosition][col] = 0;
                    b[row][col] = 1;
                    // Search with this placement
                    search(b, col + 1, moveCount + 1);
                    // Put the piece back
                    b[piecePosition][col] = 1;
                    b[row][col] = 0;
                }
                
            }
        }
    }
    
    /**
     * Locates the starting row of the piece.
     * 
     * @param b Board being checked
     * @param col Column on the board being checked.
     * 
     * @return Row row the piece is located in
     */
    private static int findPiece(int[][] b, int col) {
        for (int row = 0; row < DIM; row++) {
            if (b[row][col] == 1) return row;
        }
        
        return -1;
    }
    
    /**
     * Checks left off the position to see if it will attack any other queens.
     * 
     * @param b Board being checked 
     * @param r staring row 
     * @param c starting column
     * 
     * @return True if piece can be placed here. 
     */
    private static boolean validPosition(int[][]b, int r, int c) {
        for (int count = 1; r - count > -1 && c - count > -1; count++) {
            if (b[r - count][c - count] == 1) return false;
        }
        
        for (int count = 1; r + count < DIM && c - count > -1; count++) {
            if (b[r + count][c - count] == 1) return false;
        }
        
        for (int col = c - 1; col > -1; col--) 
            if (b[r][col] == 1) return false;
        
        return true;         
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int caseNum = 1;
        while (CIN.hasNext()) {
            int[][] board = readInTestCase();
            runTest(board);
            System.out.println("Case " + caseNum++ + ": " + MIN_MOVES);
            MIN_MOVES = 10;
        }
    }

}
