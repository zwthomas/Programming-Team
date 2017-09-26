// Zachary Thomas 11/13/16
#include <iostream>
#include <list>
using namespace std;

int main()
{
  string line;

  // Runs until EOF
  while(getline(cin, line))
  {
    list<char> beiju;
    // Creates and iterator and points it to the beginning of the list
    list<char>::iterator it = beiju.begin();

    // Steps through each character in the line
    for(int i = 0; i < line.length(); i++)
    {
      // Home key sets to beginning of list
      if(line[i] == '[')
        it = beiju.begin();

      // End key sets to end of list
      else if(line[i] == ']')
        it = beiju.end();

      // Inserts the character into the list
      else
        beiju.insert(it,line[i]);
    }

    // Sets iterator to begining of list for traversal
    it = beiju.begin();
    
    // Traverse list dereferencing the iterator to print the character at position
    while(it != beiju.end())
      cout<<*it++;

    // Newline after each line has been printed
    cout<<endl;
  }
  return 0;
}
