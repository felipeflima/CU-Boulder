#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Book.h"
using namespace std;

int main()
{
    Book newBook;
    newBook.setAuthor("wow");
    cout << newBook.getAuthor() << endl;
}