#include <iostream>
#include <fstream>
using namespace std;

int findUser (string username, string allUsers[], int userCount)
{
    for (int i = 0; i < userCount; i++)
    {
        if (allUsers[i] == username)
        {
            return i;
        }
        else 
        {
            return -1;
        }
    }
}


int getUserReadCount (string username, string allUsers[], int allRatings[][100], int userCount, int b)
{
    if (numBooks == 0 || numUsers == 0)
    {
        cout << username << " does not exist in the database" << endl;
        return -1;
    }
    int index = findUser (username, allUsers, userCount);
    if (index == -1)
    {
        cout << username << " does not exist in the database" << endl;
        return -1;
    }
    else 
    {
        if (index == -1)
        {
            cout << username << " does not exist in the database" << endl;
        }
        else
        {
            int count = 0;
            for (int i = 0; i < b; i++)
            {
                if (allRatings[index][i] != 0)
                {
                    count ++;
                }
            }
            return count;
        }
        
    }
}

int main()
{
   string choice;
    int numBooks = 0;
    int numUsers = 0;
    
    string authors[50]; // authors
    string titles[50]; // titles
    string filename;
    
    string users[100]; // users
    int ratings[100][50]; // ratings
    
    string username; 
    
    cin >> username;
    
}