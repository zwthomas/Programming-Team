// Zachary Thomas 11/2/16
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  int testcases, numPaidChars, numLines, lineCount;
  double totalCost, value;
  char indivdChar, textChars;

  cin>>testcases;
  for(int i = 0; i < testcases; i++)
  {

    lineCount = 0;
    totalCost = 0;

    cin>>numPaidChars;
    // Where the values of each character will be saved by ascii value
    double charVals[256] = {0};

    for(int j = 0; j < numPaidChars; j++)
    {
      cin>>indivdChar>>value;
      // Stores the value to the index of the character's ascii value
      charVals[int(indivdChar)] = value;
    }

    cin>>numLines;
    cin.ignore();

    while(lineCount < numLines)
    {
      textChars = getchar();
      // Adds the value at the index of the character's ascii
      totalCost += charVals[int(textChars)];
      if(textChars == '\n')
        lineCount++;
    }
    printf("%.2lf$\n", totalCost/100.0);
  }
  return 0;
}
