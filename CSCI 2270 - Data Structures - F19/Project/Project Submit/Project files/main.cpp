#include "snowday.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono> 
#include <ctime>

using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Print Graph" << endl;
  cout << "2. Add Ski Resort" << endl;
  cout << "3. Find the shortest path" << endl;
  cout << "4. Add edge" << endl;
  cout << "5. Calculate Distance" << endl;
  cout << "6. Look for runs" << endl;
  cout << "7. Quit" << endl;
}

int main(int argc, char const *argv[])
{
  Graph Snow;
  int choice = 0;
  int choice2 = 0;
  int choice6 = 0;
  int distance2 = 0;
  int distance4 = 0;
  int choice22 = 0;
  string SkiName, SkiName2;
  string SkiName4, SkiName4_b;
  string resort1, resort2;
  string location6, run6;
  string location3, location3_b;
  int startTime, endTime;
  double exactTime;
  bool checkVail = 0;
  bool checkBreck = 0;
  
  //Initialize adding these places to the graph
  Snow.addVertex("Vail");
  Snow.addVertex("Breckenridge");
  Snow.addVertex("Boulder");
  Snow.addVertex("Denver");
  Snow.addEdge("Vail", "Breckenridge", 36);
  Snow.addEdge("Vail", "Boulder", 118);
  Snow.addEdge("Vail", "Denver", 97);
  Snow.addEdge("Breckenridge", "Boulder", 91);
  Snow.addEdge("Breckenridge", "Denver", 80);
  Snow.addEdge("Boulder", "Denver", 30); 

  //displayMenu();
  cout << "Hello! Welcome to Snowday!" << endl << endl;
  while(choice != 7){
    displayMenu();
    cout << "Enter a number: " << endl;
    cin >> choice;

    cout << endl;
    switch(choice){
      displayMenu();
      case 1:
        cout << "Printing Graph... " << endl << endl;
        Snow.displayEdges();
        cout << endl;
        break;

      case 2:
        cout << "Enter the resort name you want to add to the graph: " << endl;
        cin.ignore();
        getline(cin, SkiName);
        if (Snow.graphSearch(SkiName) == 1)
        {
          cout << SkiName << " is already in the graph." << endl;
        }
        else{
          cout << "Adding " << SkiName << " to the graph..." << endl;
          Snow.addVertex(SkiName);
          cout << "Do you want to add connections to " << SkiName << "?" << endl;
          cout << "1. Yes" << endl << "2. No" << endl;
          while(choice2 != 2)
          {
            cin >> choice2;
            switch(choice2)
            {
              case 1:
                cout << "Enter which ski resort do you want to connect " << SkiName << " to" << endl;
                cin.ignore();
                getline(cin, SkiName2);
                if (!Snow.graphSearch(SkiName2))
                {
                  cout << SkiName2 << " is not a ski resort in the graph." << endl << " To add connections select oprion 4!" << endl;
                  choice2 = 2;
                  break;
                }
                cout << "What is the distance from " << SkiName << " to " << SkiName2 << "?" << endl;
                cin >> distance2; 
                Snow.addEdge(SkiName, SkiName2, distance2);
                cout << "Connecting " << SkiName << " to " << SkiName2 << "..." << endl;              
                cout << "If you want to add more connections, select option 4!" << endl << endl;
                choice2 = 2;
                break;  
              case 2:
                break;
              default:
                cout << "Invalid input. Enter 1 or 2." << endl;
                break;
            }//end of switch
          }
          choice2 = 0;//end of while loop
        }
        break; //break case 2

      case 3:
        cout << "What is the start location from your trip? " << endl;
        cin.ignore();
        getline(cin, location3);
        if(!Snow.graphSearch(location3)){
          while(!Snow.graphSearch(location3)){
            cout << location3 << " is not a ski resort in the graph. Enter a valid name: " << endl;
            getline(cin, location3);
          }//end of while
        }//end of if worng input
        
        cout << "What is the destination of your trip? " << endl;
        getline(cin, location3_b);
        if(!Snow.graphSearch(location3_b)){
          while(!Snow.graphSearch(location3_b)){
            cout << location3_b << " is not a ski resort in the graph. Enter a valid name: " << endl;
            getline(cin, location3_b);
          }//end of while
        }//end of if worng input
        cout << "The shortest path bewteen " << location3 << " and " << location3_b << " is " << Snow.DijkstraAlgorithm(location3, location3_b) << " miles." << endl << endl;

        break; //break case 3
      
      case 4:
        cout << "Enter a resort name: " << endl;
        cin.ignore();
        getline(cin, SkiName4);
        if(!Snow.graphSearch(SkiName4))
        {
          while (!Snow.graphSearch(SkiName4))
          {
            cout << SkiName4 << " is not a ski resort in the graph. Enter a valid name: " << endl;
            getline(cin, SkiName4);
          }//end of while wrong input
        }//end of if wrong input
        cout << "Enter another resort name: " << endl;
        getline(cin, SkiName4_b);
        if (Snow.adjSearch(SkiName4, SkiName4_b))
        {
          cout << SkiName4 << " and " << SkiName4_b << " are already connected." << endl << endl;
          break;
        }
        if(!Snow.graphSearch(SkiName4_b) || SkiName4_b == SkiName4)
        {
          while(!Snow.graphSearch(SkiName4_b) || SkiName4_b == SkiName4)
          {            
            cout << SkiName4_b << " is not a ski resort in the graph or it is the same as " << SkiName4 << ". Enter a valid name: " << endl;
            getline(cin, SkiName4_b);
          }
        }
        if (Snow.adjSearch(SkiName4, SkiName4_b))
        {
          cout << SkiName4 << " and " << SkiName4_b << " are already connected." << endl;
          break;
        }//end of if second name is wrong 
        cout << "What is the distance from " << SkiName4 << " to " << SkiName4_b << "?" << endl;
        cin >> distance4;
        Snow.addEdge(SkiName4, SkiName4_b, distance4);
        cout << "Connecting " << SkiName4 << " to " << SkiName4_b << "..." << endl << endl;
        break;//break case 4

      case 5:
        cout << "What resorts/city do you want to calculate the distance?" << endl << "Enter first location: " << endl;
        cin.ignore();
        getline(cin, resort1);
        if(!Snow.graphSearch(resort1))
        {
          while (!Snow.graphSearch(resort1))
          {
            cout << resort1 << " is not a ski resort in the graph. Enter a valid name: " << endl;
            getline(cin, resort1);
          }//end of while wrong input
        }//end of if wrong input
        cout << "Enter second location: " << endl;
        getline(cin, resort2);
        if(!Snow.graphSearch(resort2))
        {
          while (!Snow.graphSearch(resort2))
          {
            cout << resort2 << " is not a ski resort in the graph. Enter a valid name: " << endl;
            getline(cin, resort2);
          }//end of while wrong input
        }//end of if wrong input
        cout << endl;
        if(Snow.distanceBtw(resort1, resort2) == 0)
        {
          cout << resort1 << " and " << resort2 << " are not connected." << endl << endl;

        }
        else 
        {
          cout << "Distance between " << resort1 << " and " << resort2 << " is " <<  Snow.distanceBtw(resort1, resort2) << " miles." << endl << endl;
        }
        break;//break case 5

      case 6:
        cout << "Which resort do you want?" << endl;
        cin.ignore();
        getline(cin, location6);
        while ((location6 != "Vail" && location6 != "vail") && (location6 != "Breckenridge" && location6 != "breckenridge"))
          {
            cout << location6 << " is not a location on the map. Please enter Vail or Breckenridge." << endl;
            getline(cin, location6);
          }
        if(location6 == "Vail" || location6 == "vail")
        {
          if (checkVail == 0)
          {
            Snow.readFile("Vail.txt");
            checkVail = 1;
          }
        }
        else if (location6 == "Breckenridge")
        {
          if (checkBreck == 0)
          {
            Snow.readFile("Breckenridge.txt");
            checkBreck = 1;
          }
        }
        cout << "Do you want to: " << endl << "1. Print all the runs" << endl << "2. Look for infomation on a run?" << endl;
        cin >> choice6;
        switch(choice6)
        {
          case 1:
            if(location6 == "Vail" || location6 == "vail")
            {
              Snow.printLL();
              cout << endl;
              break;
            }
            if (location6 == "Breckenridge" || location6 == "breckenridge")
            {
              Snow.printHash();
              cout << endl;
              break;
            }

          case 2:
            cout << "Enter a run in " << location6 << ": " << endl;
            cin.ignore();
            getline(cin, run6);
            if(location6 == "Vail" || location6 == "vail")
            {
              auto start = chrono::steady_clock::now();
              Snow.LLSearch(run6);
              auto end = chrono::steady_clock::now();
              auto diff = end - start;
              cout << "Execution time: " << chrono::duration <double, milli> (diff).count() << " ms" << endl << endl;
              break;
            }
            if (location6 == "Breckenridge" || location6 == "breckenridge")
            {
              Snow.HTSearch(run6);
              break;
            }

            break;
        }
      
      break;//break case 6

      case 7:
        cout << "Exiting the program... Goodbye" << endl;
        break;//break case 6
        
      default:
          cout << "Invalid input. Enter a number between 1 and 5." << endl;
          break;//break default
    }
  }

}