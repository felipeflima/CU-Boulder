#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

double simScore(string s1, string s2)
{
    double count = 0;
    double hamming_distance = 0;
    double similarity_score = 0;
    if (s1 == "" || s2 == "" || s1.length() != s2.length())
    {
        return 0;
    }
    else if (s1.length() == s2.length())
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s2[i])
            {
                count++;
            }
        }
        hamming_distance = (s1.length() - count);
        similarity_score = (s1.length() - hamming_distance) / s1.length();
    }
    return similarity_score;
}

int main()
{
    cout << simScore("ABCD", "ABES");
}