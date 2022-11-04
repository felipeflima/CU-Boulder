// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1 // Recitation 8 - Problem #4

#include <iostream>
#include <fstream>
using namespace std;

/**
 * Algorithm: function will convert the first n values of the array into doubles and compute their average then write to the file the name and the average
 *  1. create an output file stream for writing to file
 *  2. open file
 *  3. check if file is open
 *      a. check gor special cases (if n quals 0 print the name / if the first index of the array is 0 exit the function)
 *  4. if it is not a special case, create avg variable to calculate the average of the numerical values in the array 
 *  5. write to the function the name (last value in the array)
 *  6. for loop and update the avg by adding every numerical value
 *  7. calculate avg by dividing the current value of avg by n and write it to the function
 *  8. if file is not open, print "file open failed"
 *  9. test cases
 */

void saveData (string s, string a[], int n, int size) // function that takes in a string paramenter, an array of strings, the numeber of numerical values in the array and the size of the array
{
    ofstream filename; // create an output file stream for writing to file
    filename.open(s); // open the file passed to the function as string s with the file stream
    if (filename.is_open()) // if file is open
    {
       if (n == 0) // is n (number of numerical values in the array) is equal to 0
       {
           filename << "Name: " << a[size - 1]; // write to the file the last index in the array
           return; // returns so it exits the function
       }
       if (a[0] == "") // if the first index in the array is equal to an empty string 
       {
           return; // returns so it exits the function
       }
       else // if none of the conditions above are met
       {
           double avg = 0; // create avg variable to calculate the average of the numerical values in the array 
           filename << "Name: " << a[size - 1] << endl; // writes to the function
           for (int i = 0; i < n; i++) // for loop to run through the array
           {
               avg += stod(a[i]); // sets avg equal to its previous value plus the value of the numerical values in the array as a double
           }
           filename << "Avg: " << avg/n << endl; // writes to the function the avg by dividing the current value of avg by n
       }
    }
    else // if the file is not open
    {
        cout << "file open failed" << endl; // print "file open failed"
    }
}

int main()
{
    string data[4] = {"2.3", "-1.5", "0.8", "Garth"};
    saveData("file.txt", data, 0, 4);
    // expected - Name: Garth
    string data[5] = {"0", "0", "0", "0", "G"};
    string filename = "my_data.txt";
    saveData(filename, data, 4, 5);
    // expected - nothing
    string data[4] = {"3.2", "-1.1", "0.4", "Manzoni"};
    string filename = "my_data2.txt";
    saveData(filename, data, 3, 4);
    DisplayFile(filename);
    // expected - Name: Manzoni
               // Avg: 0.833333
}