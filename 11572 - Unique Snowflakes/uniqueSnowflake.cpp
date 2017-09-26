// Zachary Thomas 10/31/16
#include <iostream>
#include <map>
using namespace std;

int getBags(int size);

int main()
{
	int testCases, numFlakes;
	// Total number of test cases in the simulation
	cin>>testCases;
	for(int i = 0; i < testCases; i++)
	{
		int numFlakes;
		// Number of flakes that will run through the machine in this test case
		cin>>numFlakes;
		// Outputs the maximum number of unique snowflakes in a bag
		cout<< getBags(numFlakes)<<endl;
	}
	return 0;
}

int getBags(int size)
{
  long position, streak, flake, max = 0, last = 0;
  map<long,int> flakeBag;
  long allFlakes[size];

  for( int i = 0; i < size; i++ )
	{
		// Reads in the individual flakes
		cin>>flake;
		// Saves them to an array for use to index into the map
    allFlakes[i] = flake;

		// If evaluates if the flake is already in the map
    if(flakeBag.find(flake) != flakeBag.end())
    {
      // Holds the position of the occurance of the flake that is already in the map
      position = flakeBag.find(flake)->second;
      // Holds the max number of unique snowflakes that fit in this particular bag
      streak = flakeBag.size();

      if( streak > max )
        max = streak;

			// Starting at the current front of the bag removes all the flakes up to
			// and includeing the one that has been duplicated
			while(last <= position)
			{
      	flakeBag.erase(allFlakes[last]);
				last++;
			}
		}
		// Puts the flake in the bag
		flakeBag[flake] = i;
	}

	// If the last element of the bag is not a duplicate, check to see if the bag
	// has more flakes than the current max
	if(flakeBag.size() > max)
		max = flakeBag.size();

	return max;
}
