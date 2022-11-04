#include <iostream>
#include <fstream>
using namespace std;

int findBookReview (string title, string titles[], int numBooks)
{
    for (int i = 0; i < numBooks; i++)
    {
        if (titles[i] == title)
        {
            return i;
        }
    }
    return -1;
}

double calcAvgRating (string title, string titles[50], int ratings[100][50], int numUsers, int numBooks)
{
    if (numBooks == 0 || numUsers == 0)
    {
        cout << title << " does not exist in the database" << endl;
        return -1;
    }
    int index = findBookReview (title, titles, numBooks);
    if (index == -1)
    {
        cout << title << " does not exist in the database" << endl;
        return -1;
    }
    else 
    {
        if (index == -1)
        {
            cout << title << " does not exist in the database" << endl;
        }
        else
        {
            int count = 0;
            double avg = 0;
            for (int i = 0; i < numBooks; i++)
            {
                if (ratings[index][i] != 0)
                {
                    count++;
                    avg += i;
                }
                avg = count/avg;
            }
            return avg;
        }
        
    }
}

int main()
{
    average = calcAvgRating(title, users, ratings, numUsers, numBooks);
}