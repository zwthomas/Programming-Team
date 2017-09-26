/* Zachary Thomas
 * 1/25/17
 * Solution to UVAJudge 12854 - Automated Checking Machine
 */

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Main
{
	public static final Scanner cin = new Scanner(System.in);
	public static final int PLUG_LENGTH = 5;

	/**
	* Reads in the connection type and saves it in a queue.
	*/

	public static Queue<Integer> fillQueue()
	{
		Queue<Integer> q = new LinkedList();
		
		for(int i = 0; i < PLUG_LENGTH; i++)
		{
			q.add(cin.nextInt()); // Adds each input to the queue
		}

		return q;
	}

	/**
	* Checks to see if the plug and outlet are compatible. If so return 'Y', 
	* else return 'N'.
	*/

	public static char test(Queue<Integer> q1, Queue<Integer> q2)
	{
		// While there are still connection points left to check
		while(!q1.isEmpty())
		{	
			// If the two connection points are not compatible we are done
			if(q1.remove() == q2.remove())
			{
				return 'N';
			}
		}
		// If we make it this far they are compatible
		return 'Y';
	}
	
	public static void main(String[] args)
	{
		Queue<Integer> outlet;
		Queue<Integer> plug;

		// While there is still more input
		while(cin.hasNext())
		{
			// Reads in connection points
			outlet = fillQueue();
			plug = fillQueue();

			System.out.println(test(outlet,plug));
		}
	}
}