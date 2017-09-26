// Zachary Thomas 11/14/16
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int jackCds, jillCds, cd;

	// Reads in number of inputs in the first test case
	cin>>jackCds>>jillCds;

	// Runs until both have zero cds
	while(jackCds + jillCds != 0)
	{
		// Using set because all elements of a set are unique
		set<int> collection;
		
		// Reads in all the cds and puts them in the set
		for(int i = 0; i < jackCds + jillCds; i++)
		{
			cin>>cd;
			collection.insert(cd);
		}
		
		// Prints out the number that they do not both have
		cout<<jackCds + jillCds - collection.size()<<endl;

		// Reads in number of inputs in the next test case
		cin>>jackCds>>jillCds;
	}

	return 0;
}