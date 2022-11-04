#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

struct wordItem{
    string word;
    int count;
};

void resize(int **arrayPtr, int *capacity)
{
	int newCapacity = 2 *(*capacity); // increase the capacity by two times
	int *newArray = new int[newCapacity]; // dynamically allocate an array of size newCapacity
	for (int i = 0; i < *capacity; i++) // copy all data from oldArray to newArray
	{
		newArray[i] = *(*arrayPtr+i);
		//cout << newArray[i] << endl;
	}
	delete  *arrayPtr; //TODO free the memory associated with oldArray
	*arrayPtr = newArray;
	*capacity = newCapacity;
}

void getStopWords (const char *ignoreWordFileName, string ignoreWords[])
{
    string file = ignoreWordFileName;
    string temp;
    ifstream ignoreStream;
    ignoreStream.open(file);
    int i = 0;
    if (ignoreStream.is_open())
    {
        while (getline(ignoreStream, temp))
        {
            ignoreWords[i] = temp;
            i++;
        }
        ignoreStream.close();
    }
    else
    {
        cout << "Failed to open" << ignoreWordFileName << endl;
    }
}

bool isStopWord(string word, string ignoreWords[])
{
    for (int i = 0; i < 50; i++)
    {
        if (word ==  ignoreWords[i])
        {
            return 1;
        }
    }
    return 0;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        counter += uniqueWords[i].count;
    }
    return counter;
}

void arraySort(wordItem uniqueWords[], int length)
{
    wordItem t;
    wordItem t2;
    for (int i = 0; i < length; i++)
    {
        for(int j = i+1; j < length; j++)
        {
            if (uniqueWords[i].count < uniqueWords[j].count)
            {
                t = uniqueWords[i];
                t2 = uniqueWords[i];
                uniqueWords[i] = uniqueWords[j];
                uniqueWords[i] = uniqueWords[j];
                uniqueWords[j] = t;
                uniqueWords[j] = t2;
            }
        }
    }
}

void printNext10 (wordItem wordItemList[], int startRank, int totalWords)
{
    float poc;
    for (int i = startRank; i < startRank+10; i++)
    {
        poc = (float) wordItemList[i].count/totalWords;
        cout << fixed << setprecision(4) << poc << " - " << wordItemList[i].word << endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }
    string ignore[100];
    string filename = argv[2];
    ifstream readFrom;
    readFrom.open(filename);
    if (readFrom.is_open())
    {
        getStopWords(argv[3], ignore);
        int capacity = 100;
        wordItem *arrayPtr;
        //arrayPtr = new int[capacity];



    }
    else
    {
      cout << "Failed to open file" << endl;
    }

}
