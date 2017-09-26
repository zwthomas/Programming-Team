/*
 * Zachary Thomas
 * CSM 3070 Assignmnet 3
 * 9/17/2017
 * UVa Judge: 10815 - Andy's First Dictionary
 */

import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    private static final Scanner CIN = new Scanner(System.in);

    /**
     * Reads in the input. Saves the unique words.
     * 
     * @return Returns a TreeSet of all the words
     */
    private static TreeSet<String> readInput() {
        TreeSet<String> input = new TreeSet<>();
        String in;

        while (CIN.hasNext()) {
            boolean added = false;
            StringBuilder s = new StringBuilder();
            in = CIN.next().toLowerCase(); // Reads in token

            // Goes through all the letters in the token
            for (int ndx = 0; ndx < in.length(); ndx++) {
                // If the letter is lower case a-z save it
                if (in.charAt(ndx) > 96 && in.charAt(ndx) < 123) {
                    added = false;
                    s.append(in.charAt(ndx));
                    // Else that is the end of our current word
                } else {
                    added = true;
                    input.add(s.toString());
                    s = new StringBuilder();
                }
            }
            if (!added) {
                input.add(s.toString()); // Probably responsible for extra line
            }
        }
        return input;
    }

    /**
     * Displays the words in alphabetical order.
     * 
     * @param words words to be displayed
     */
    private static void printWords(TreeSet<String> words) {
        words.pollFirst(); // Gets rid of extra line at beginning
        while (!words.isEmpty()) {
            System.out.println(words.pollFirst());
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        TreeSet<String> input = readInput();
        printWords(input);
    }

}
