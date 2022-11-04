#include <iostream>
#include <fstream>
using namespace std;

void printAllBooks (string titles[], string authors[], int b)
{
    if (b == 0)
    {
        cout << "No books are stored" << endl;
    }
    else 
    {
        cout << "Here is a list of books" << endl;
        cout << titles[i] << " by " << authors[i] << endl;
    }
}

int main()
{
    printAllBooks()
}