/*
Solution to UVa problem 978 - Lemmings Battle!
Zachary Thomas 11/20/16
*/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> fillQueue( int numberOfElements);
void warSimulation(priority_queue<int>&, priority_queue<int>&, int);
void battleSimulation(priority_queue<int>&, priority_queue<int>&, int);
void printResult(priority_queue<int>&, priority_queue<int>&, int, int);

int main()
{
	int testCases, battlefields, numGreen, numBlue;

	// Reads in the number of test cases to run
	cin>>testCases;

	for(int i = 0; i < testCases; i++)
	{
		// Reads in the number of battles that can happen at a time 
		// and the number on each team
		cin>>battlefields>>numGreen>>numBlue;
		
		// Creates and fills a priority queue for each team so the strongest come first
		priority_queue<int> green = fillQueue(numGreen);
		priority_queue<int> blue =  fillQueue(numBlue);

		warSimulation(green, blue, battlefields);

		printResult(green, blue, i, testCases);
	}
	
	return 0;
}

// This function reads in the strengths of the lemmings on a team
priority_queue<int> fillQueue( int numberOfElements)
{
	int element;
	priority_queue<int> pq;

	for(int i = 0; i < numberOfElements; i++)
	{
		// Reads in the powers
		cin>>element;

		// Puts the powers in the queue
		pq.push(element);
	}
	
	// Returns the priority queue of powers
	return pq;
}

// Simulates the fighting of all the lemmings in each test case
void warSimulation(priority_queue<int>& team1, priority_queue<int>& team2, int battleSize)
{
	// Runs until one of the teams does not have any memebers left
	while(team1.size() > 0 && team2.size() > 0)
	{
		int size1 = team1.size(), size2 = team2.size();
		
		// If both teams have more members than battlefields 
		if(size1 >= battleSize && size2 >= battleSize)
			battleSimulation(team1, team2, battleSize);
		
		/* 
		The next two cases will run if one or both of the two teams do not have enough 
		members to fill all the battlefields. In which case, the number of battles that 
		will take place is equal to the size of the smaller team
		*/
		
		// Team 1 is smaller
		else if( size1 <= size2)
			battleSimulation(team1, team2, size1);

		// Team 2 is smaller
		else
			battleSimulation(team1, team2, size2);
	}

	return;
}

void battleSimulation(priority_queue<int>& team1, priority_queue<int>& team2, int size)
{
	int top1, top2;

	// The holders are needed to ensure that a lemming can only fight once a round
	queue<int> holder1,holder2;


	for(int i = 0; i < size; i++)
	{
		top1 = team1.top();
		top2 = team2.top();

		// Both lemmings die
		if(top1 == top2)
		{
			team1.pop();
			team2.pop();
		}

		// Lemming from team 2 dies
		else if(top1 > top2)
		{
			team1.pop();
			team2.pop();
			holder1.push(top1 - top2);
		}

		// Lemming from team 1 dies
		else
		{
			team1.pop();
			team2.pop();
			holder2.push(top2 - top1);
		}
	}

	// Puts the victors from team one back in the priority queue
	while(holder1.size() > 0)
	{
		team1.push(holder1.front());
		holder1.pop();
	}

	// Puts the victors from team 2 back in the priority queue
	while(holder2.size() > 0)
	{
		team2.push(holder2.front());
		holder2.pop();
	}

	return;
}


void printResult(priority_queue<int>& team1, priority_queue<int>& team2, int round, int totalRounds)
{
	/*
	Round and totalRounds are needed to be passes in, because a presentation error will be recieved
	if a new line is printed after the last test case. The if statements in each condition take care
	of that.
	*/

	// Both are out of members
	if(team1.size() == 0 && team2.size() == 0)
	{
		cout<<"green and blue died"<<endl;

		if(round != totalRounds - 1) 
			cout<<endl;
	}
	
	// Green wins
	else if(team1.size() != 0)
	{
		cout<<"green wins"<<endl;

		// Displays the surviving victors
		while(team1.size() > 0)
		{
			cout<<team1.top()<<endl;
			team1.pop();
		}
		
		if(round != totalRounds - 1) 
			cout<<endl;
	}

	// Blue wins 
	else
	{
		cout<<"blue wins"<<endl;

		// Displays the surviving victors
		while(team2.size() > 0)
		{
			cout<<team2.top()<<endl;
			team2.pop();
		}
		
		if(round != totalRounds - 1) 
			cout<<endl;
	}

	return;
}