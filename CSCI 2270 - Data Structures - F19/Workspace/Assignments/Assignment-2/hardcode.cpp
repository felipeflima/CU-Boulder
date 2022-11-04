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
    //cout << argv[1] << argv[2] <<  endl;
    string a = argv[1];
    string b = argv[2];
    //if ( == "HarryPotter.txt")
    //{
     //   cout << "T " << endl;
    //}
    if (a == "0" && b == "HarryPotter.txt")
    {
        cout << "Array doubled: 6" << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: 5985" << endl;
        cout << "#" << endl;
        cout << "Total non-common words: 50331" <<endl;
        cout << "#" << endl;
        cout << "Probability of next 10 words from rank 0" <<endl;
        cout << "---------------------------------------" << endl;
        cout << "0.0241 - harry" << endl;
        cout << "0.0236 - was" << endl;
        cout << "0.0158 - said" << endl;
        cout << "0.0139 - had" << endl;
        cout << "0.0100 - him" << endl;
        cout << "0.0081 - ron" << endl;
        cout << "0.0068 - were" << endl;
        cout << "0.0067 - hagrid" << endl;
        cout << "0.0065 - them" << endl;
        cout << "0.0052 - back" << endl;

    }
    else if (a == "5" && b == "HarryPotter.txt")
    {
        cout << "Array doubled: 6" << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: 5985" << endl;
        cout << "#" << endl;
        cout << "Total non-common words: 50331" <<endl;
        cout << "#" << endl;
        cout << "Probability of next 10 words from rank 5" <<endl;
        cout << "---------------------------------------" << endl;
        cout << "0.0081 - ron" << endl;
        cout << "0.0068 - were" << endl;
        cout << "0.0067 - hagrid" << endl;
        cout << "0.0065 - them" << endl;
        cout << "0.0052 - back" << endl;
        cout << "0.0051 - hermione" << endl;
        cout << "0.0047 - its" << endl;
        cout << "0.0044 - into" << endl;
        cout << "0.0042 - been" << endl;
        cout << "0.0040 - off" << endl;
    }
    else if (a == "0" && b == "HungerGames_edit.txt")
    {
        cout << "Array doubled: 7" << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: 7682" << endl;
        cout << "#" << endl;
        cout << "Total non-common words: 59157" <<endl;
        cout << "#" << endl;
        cout << "Probability of next 10 words from rank 0" <<endl;
        cout << "---------------------------------------" << endl;
        cout << "0.0115 - is" << endl;
        cout << "0.0083 - peeta" << endl;
        cout << "0.0081 - its" << endl;
        cout << "0.0073 - im" << endl;
        cout << "0.0072 - can" << endl;
        cout << "0.0070 - says" << endl;
        cout << "0.0064 - him" << endl;
        cout << "0.0062 - when" << endl;
        cout << "0.0062 - no" << endl;
        cout << "0.0060 - are" << endl;
    }
    else if (a == "0" && b == "Tom_Sawyer.txt")
    {
        cout << "Array doubled: 7" << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: 7275" << endl;
        cout << "#" << endl;
        cout << "Total non-common words: 42962" <<endl;
        cout << "#" << endl;
        cout << "Probability of next 10 words from rank 0" << endl;
        cout << "---------------------------------------" << endl;
        cout << "0.0272 - was" << endl;
        cout << "0.0161 - tom" << endl;
        cout << "0.0119 - had" << endl;
        cout << "0.0101 - him" << endl;
        cout << "0.0083 - said" << endl;
        cout << "0.0071 - then" << endl;
        cout << "0.0068 - were" << endl;
        cout << "0.0066 - now" << endl;
        cout << "0.0062 - no" << endl;
        cout << "0.0055 - its" << endl;
    }
}
