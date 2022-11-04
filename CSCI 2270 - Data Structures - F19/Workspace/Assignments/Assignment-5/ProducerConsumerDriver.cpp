/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer prod;
	string line;
	int choice;
	int numItems;
	int Icons;
	string iitem;
	int qSize;
	while (choice != 3)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Enter the number of items to be produced:" << endl;
				cin >> numItems;
				for (int i = 0; i < numItems; i ++)
				{
					cout << "Item" << i+1 << ":" << endl;
					if (i == 0)
					{
						cin.ignore();
					}
					getline(cin, line);
					prod.enqueue(line);
				}
				break;

			case 2:
				cout << "Enter the number of items to be consumed:" << endl;
				cin >> Icons;
				for (int j = 0; j < Icons; j++)
				{
					if (prod.isEmpty())
					{
						j = Icons;
					}
					iitem = prod.peek();
					cout << "Consumed: " << iitem << endl;
					prod.dequeue();
					if (prod.isEmpty())
					{
						j = Icons;
						cout << "No more items to consume from queue" << endl;
					}
				}
				break;
		 }

		 if (choice == 3)
		 {
			 qSize = prod.queueSize();
			 cout << "Number of items in the queue:" << qSize << endl;
		 }
	 }
}
