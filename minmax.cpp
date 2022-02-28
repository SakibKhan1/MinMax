/*
Author: Sakib Khan
Course: CSCI 135
Instructor: Tong Yi
Assignment: Min-Max
This program will print the minimum and maximum values from
the NYC Open Data website.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
//includes all necessary libraries

using namespace std;
int main()
{
    string date;
    double eastSt, eastEl, westSt, westEl, minimum, maximum;
    int i = 0;
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk;        
    getline(fin, junk); 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
       
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 

        if(i == 0) 
        {
            minimum = eastSt;
            maximum = eastSt;
        }
        if (minimum > eastSt)
            minimum = eastSt;
        if (maximum < eastSt)
            maximum = eastSt;
        i++;
    }

    cout << "minimum storage in East basin: " << minimum << endl;
    cout << "Maximum storage in East basin: " << maximum << endl;
    fin.close();
    return 0;
}
