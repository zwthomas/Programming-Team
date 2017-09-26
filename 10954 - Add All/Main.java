/*
 * Zachary Thomas
 * CSM 3070 Assignment 2
 * 9/5/2017
 * UVa Judge: 10954 - Add All
 */
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
    private static final Scanner CIN = new Scanner(System.in);

    /**
     * Reads in the numbers that are supposed to be summed and saves them in a 
     * priority queue with the smallest at the top.
     * 
     * @param numIn Number of numbers to be summed
     * 
     * @return Priority queue containing the numbers 
     */
    private static PriorityQueue<Integer> readNums(int numIn) {
        PriorityQueue<Integer> numbers = new PriorityQueue<>();
        for (int i = 0; i < numIn; i++) {
            numbers.add(CIN.nextInt());
        }
        return numbers;
    }
    
    /**
     * Sums the numbers that were input. The goal is to add the smallest numbers 
     * first. This means that when we sum two numbers, we have to put that sum 
     * back in the queue.
     * 
     * @param q the queue of numbers
     * 
     * @return the min cost sum 
     */
    private static int sumNumbers(PriorityQueue<Integer> q) {
        int sum;
        int totalSum = 0;
        
        while (q.size() > 1) {
            // Sums top 2 in queue
            sum = q.poll() + q.poll();
            totalSum += sum;
            // Puts sum back in queue
            q.add(sum);
        }
        
        return totalSum;
    }
            
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        PriorityQueue<Integer> numbers = new PriorityQueue<>(); 
        int numInRow;
        
        // Reads in the number of numbers to be added and is terminated with 0
        while ((numInRow = CIN.nextInt()) != 0) {
            
            // Displays the result of reading in the numbers and summing them
            System.out.println(sumNumbers(readNums(numInRow)));  
        }
        
    }
    
}
