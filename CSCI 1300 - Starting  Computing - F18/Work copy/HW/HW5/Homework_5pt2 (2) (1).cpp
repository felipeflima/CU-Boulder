// CS1300 Fall 2018
// Author: Felipe Lima
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/feli0059/csci1300fl1// Homework 5

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

/** 
 * Algorithm: find the best matching amongst the three known genomes with a sequence from the unknown bacteria.
 *  1. create the analyzer function 
 *      a. analyze edge cases and the normal cases
 *          i. edge cases
 *              1. if any of the strings are empty, display: "Genome and sequence cannot be empty."
 *              2. if any of the length of the genome strings don't match, display: "Genome length does not match."
 *              3. if the sequence of the unknown bacteria is greater than any of the genome strings, display: "Sequence length must be smaller than genome length."
 *          ii. normal cases
 *              1. create variable for the max similarity score of each genome 
 *              2. create for loop to run through all the characters in the genome
 *              3. if maxg1 is less than the previous maxg1 value (first one is 0), reassign it to the similarity score of the first string (finding the similarity socre by calling the function simScore)
 *              4. if maxg2 is less than the previous maxg2 value (first one is 0), reassign it to the similarity score of the second string
 *              5. if maxg3 is less than the previous maxg3 value (first one is 0), reassign it to the similarity score of the third string
 *      b. call the function final passing the values of maxg1, maxg2, and maxg3
 * 2. create simScore function (finds the similarity score of each genome)
 *      a. create variable count and assign it to 0 (count will be the number of times a character matches between the genome and the sequence)
 *      b. create variable hamming_distance and assign it to 0 (this will be the number of char that don't match)
 *      c. create variable similarity_score and assign it to 0 (this will calculate whast is called similarity score)
 *      d. if any of the strings are empty of they have differetn lengths, return 0
 *      e. if the lenght os the strings match
 *          i. for loop to run through the string
 *              1. if the characters match, add one to count
 *          ii. reassigns the value of hamming_distance to the length of the string minus the number of times the characters match
 *          iii. reassign the value of similarity_score to the (length of the string minus the hamming distance) divided by the string length
 *      f. return similarity_score
 * 3. create final function that will determine, based one which similarity score was the highest, what genome is the best match for the sequence and siplay the appropriate message
 */


double final(double simA, double simB, double simC) // final function -> decides what is the best match 
{
    if (simA > simB && simA > simC) // if the similarity score of genome 1 is the highest
    {
        cout << "Genome 1 is the best match." << endl; // display: "Genome 1 is the best match."
    }
    else if (simB > simA && simB > simC) // if the similarity score of genome 2 is the highest
    {
        cout << "Genome 2 is the best match." << endl; // display: "Genome 2 is the best match."
    }
    else if (simC > simB && simC > simA) // if the similarity score of genome 3 is the highest
    {
        cout << "Genome 3 is the best match." << endl; // display: "Genome 3 is the best match."
    }
    else if (simC == simB && simC > simA) // if the similarity score of genome 2 and 3 are equal and the highest
    {
        cout << "Genome 2 is the best match." << endl; // display: "Genome 2 is the best match."
        cout << "Genome 3 is the best match." << endl; // display: "Genome 3 is the best match."
    }
    else if (simA == simB && simA > simC) // if the similarity score of genome 1 and 2 are equal and the highest
    {
        cout << "Genome 1 is the best match." << endl; // display: "Genome 1 is the best match."
        cout << "Genome 2 is the best match." << endl; // display: "Genome 2 is the best match."
    }
    else if (simA == simC && simA > simB) // if the similarity score of genome 1 and 3 are equal and the highest
    {
        cout << "Genome 1 is the best match." << endl; // display: "Genome 1 is the best match."
        cout << "Genome 3 is the best match." << endl; // display: "Genome 3 is the best match."
    }
    else if (simA == simB && simA == simC) // if the similarity score of all the genomes is the same
    {
        cout << "Genome 1 is the best match." << endl; // display: "Genome 1 is the best match."
        cout << "Genome 2 is the best match." << endl; // display: "Genome 2 is the best match."
        cout << "Genome 3 is the best match." << endl; // display: "Genome 3 is the best match."
    }
}

double simScore(string s1, string s2) // function to find the similarity score of each genome
{
    double count = 0; // create variable count and assign it to 0
    double hamming_distance = 0; // create variable hamming distance and assign it to 0
    double similarity_score = 0; // create variable similarity score and assign it to 0
    if (s1 == "" || s2 == "" || s1.length() != s2.length()) // if any of the strings are empity of they have differetn lengths
    {
        return 0; // return 0
    }
    else if (s1.length() == s2.length()) // if the lenght os the strings match
    {
        for (int i = 0; i < s1.length(); i++) // for loop to run through the string
        {
            if (s1[i] == s2[i]) // if the characters match
            {
                count++; // add one to count
            }
        }
        hamming_distance = (s1.length() - count); // reassigns the value of hamming_distance to the length of the string minus the number of times the characters match
        similarity_score = (s1.length() - hamming_distance) / s1.length(); // reassign the value of similarity_score to the (length of the string minus the hamming distance) divided by the string length
    return similarity_score; // return similarity_score
}

void analyzer(string g1, string g2, string g3, string seq) // fuction will analyze each case and decide what to do
{
    if (g1 == "" || g2 == "" || g3 == "" || seq == "")// if any of the strings are empty
    {
        cout << "Genome and sequence cannot be empty." << endl; //  if any of them don't match, display: "Genome and sequence cannot be empty."
    }
    else if (g1.length() != g2.length() || g2.length() != g3.length() || g1.length() != g3.length()) // if any of the length of the genome strings don't match
    {
        cout << "Genome length does not match." << endl; //  display: "Genome length does not match."
    }
    else if (seq.length() > g1.length() || seq.length() > g2.length() || seq.length() > g3.length()) // if the sequence of the unknown bacteria is greater than any of the genome strings
    {
        cout << "Sequence length must be smaller than genome length." << endl; // display: "Sequence length must be smaller than genome length."
    }
    else // if any of the consitions above are not met
    {
        double maxg1, maxg2, maxg3 = 0; // create variable for the max similarity score of each genome 
        for (int i = 0; i < g1.length(); i++) // for loop to run through all the characters in the genome
        {
            if (maxg1 < simScore(g1.substr(i, seq.length()), seq)) // if maxg1 is less than the previous maxg1 value (first one is 0)
            {
                maxg1 = simScore(g1.substr(i, seq.length()), seq); // reassign it to the similarity score of the first string
            }
            if (maxg2 < simScore(g2.substr(i, seq.length()), seq)) // if maxg2 is less than the previous maxg2 value (first one is 0)
            {
                maxg2 = simScore(g2.substr(i, seq.length()), seq); // reassign it to the similarity score of the second string
            }
            if (maxg3 < simScore(g3.substr(i, seq.length()), seq)) // if maxg3 is less than the previous maxg3 value (first one is 0)
            {
                maxg3 = simScore(g3.substr(i, seq.length()), seq); // reassign it to the similarity score of the second string
            }
        }
        final (maxg1, maxg2, maxg3); // call final passing the values of maxg1, maxg2, and maxg3
    }
}


int main()
{
    analyzer("AAC", "GTT", "AGT", "ACT"); // expected outcome: Genome 3 is the best match.
    analyzer("", "GCT", "AAA", "GTA"); // expected outcome: Genome and sequence cannot be empty.
    analyzer("TAAGGCA", "TCTGGGC", "CTAATAT", "AAG"); // expected outcome: Genome 1 is the best match.
    analyzer("AAGT", "GTTA", "ACGT", "GGTTAAC"); // expected outcome: Sequence length must be smaller than genome length.
    analyzer("AA", "GTAA", "AGAA", "GCA"); // expected outcome: Genome length does not match.
    analyzer("AAT", "GAT", "AAC", "GTT"); // expected outcome: Genome 2 is the best match.
    cout << simScore("ACT", "ACT") << endl; // expected outcome: 1
    cout << simScore("AGTA", "AGGT") << endl; // expected outcome: 0.5 
    cout << simScore("AGTA", "ACA") << endl; // expected outcome: 0
    cout << simScore("ACA", "ACTG") << endl; // expected outcome: 0
    cout << simScore("ACTGA", "ACTGA") << endl; // expected outcome: 1 
    cout << simScore("ACTGA", "AGTGA") << endl; // expected outcome: 0.9
    final(.7, .9, 1); // expected outcome: Genome 3 is the best match.
    final(.8, 0, .55); // expected outcome: Genome 1 is the best match.
    final(.75, .75, .4); // expected outcome: Genome 1 is the best match.
                                           // Genome 2 is the best match.
    final(.43, 1, .54); // expected outcome: Genome 2 is the best match.
    final(.7, 1, 1); // expected outcome: Genome 2 is the best match.
                                       // Genome 3 is the best match.
    final(1, 1, 1); // expected outcome: Genome 1 is the best match.
                                      // Genome 2 is the best match.
                                      // Genome 3 is the best match.
}