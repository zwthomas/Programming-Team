// Zachary Thomas 11/13/16
#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int testCases, numInQueue, position, priority, minutes, top;

  cin>>testCases;

  for(int i = 0; i < testCases; i++)
  {
    // Resets the time
    minutes = 0;
    priority_queue<int> printPriority;
    queue<int> printerQueue;

    cin>>numInQueue>>position;

    // Reads in the priorities of the jobs
    for(int j = 0; j < numInQueue; j++)
    {
      cin>>priority;
      printerQueue.push(priority);
      printPriority.push(priority);
    }

    // Simulates the printing
    while(position != -1)
    {
      // If the priority of the front print job is does not have highest priority
      if( printerQueue.front()!= printPriority.top())
      {
        // Put the value at the front of the queue on the back
        printerQueue.push(printerQueue.front());
        // Remove it from the front
        printerQueue.pop();

        // If your print job is at the front move it to the back
        if(position == 0 )
          position = numInQueue-1;

        // If not move it closer to the front
        else
          position--;
      }

      // If the priorities do match
      else
      {
        // Remove the value from both queues
        printerQueue.pop();
        printPriority.pop();

        // If your print job was at the front it will now have a position of -1
        // causing loop termination
        position--;
        numInQueue--;
        minutes++;
      }
    }

    // Prints total minutes
    cout<<minutes<<endl;
  }
  return 0;
}
