// Zachary Thomas 11/1/16
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
  int testCases;
  string tree;
  cin>>testCases;
  cin.ignore();
  // Ignores the blank line between the number of test cases and the first case
  cin.ignore();
  for(int i = 0; i < testCases; i++ )
  {
    int totalTrees = 0;
    string tree;
    vector<string> forest;
    map<string,int> treeFreq;

    // Reads in all the trees in a test case. Stops when it reaches a blank line
    // between test cases
    while(getline(cin,tree) && !tree.empty())
    {
      // Add it to vector and map if not already in
      if( treeFreq.find(tree) == treeFreq.end())
      {
        treeFreq[tree] = 1;
        forest.push_back(tree);
      }
      // Adds to the count if already in
      else
        treeFreq[tree] += 1;

      totalTrees++;
    }

    sort(forest.begin(), forest.end());
    for(int j = 0; j < treeFreq.size(); j++)
    {
      printf("%s %.4f\n", forest[j].c_str(), (float) treeFreq[forest[j]]/totalTrees * 100);
    }
    // Prints a blank line between the output of frequences, but not after the last
    if( i < testCases - 1)
      cout<<endl;
  }
  return 0;
}
