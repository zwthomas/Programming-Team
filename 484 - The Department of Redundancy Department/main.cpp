/*
 * Zachary Thomas
 * CSM 3070 Assignment 3
 * 9/17/2017
 * UVa Judge: 484 - The Department of Redundancy Department
 */

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

vector<int>* countInput(map<int, int> *m);
void printResults(map<int,int> *m, vector<int> *v);

int main() {
    map<int, int> *freq = new map<int, int>();
    vector<int> *order = countInput(freq);
    printResults(freq, order);

    return 0;
}

/**
 * Reads in all of the input. Saves each unique number to a vector to maintain the order they should be printed out.
 * Then saves the number and frequency of its occurrences in Map m.
 *
 * @param m - Pointer to the map in which the frequencies are to be stored
 *
 * @return  A vector holding the order the elements should be printed.
 */
vector<int>* countInput(map<int, int> *m) {
    vector<int> *nums = new vector<int>();
    int holder;

    // While there are still numbers to read
    while (cin >> holder) {
        // If the number is nor already in the map
        if ((*m).find(holder) == (*m).end()) {
            (*nums).push_back(holder); // Put it in the vector
            (*m)[holder] = 0; // Put it in the map
        }
        (*m)[holder]++; // Increment the count for that number
    }
    return nums;
}

/**
 *  Displays the frequencies for each number. Uses the vector to maintain the printing order.
 *
 * @param m - frequencies
 * @param v - order
 */
void printResults(map<int,int> *m, vector<int> *v) {
    vector<int>::iterator it = (*v).begin();

    // While there is a number that we have not displayed the frequency
    while (it != (*v).end()) {
        cout << (*it) << " " <<(*m)[(*it)]  <<  endl;
        it++;
    }
}