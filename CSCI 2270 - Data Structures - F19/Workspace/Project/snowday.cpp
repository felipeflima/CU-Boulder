#include "snowday.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include <chrono> 

using namespace std;

void Graph::addEdge(string v1, string v2, int num)
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == v1)
    {
      for (unsigned int j = 0; j < vertices.size(); j++)
      {
        if (vertices[j]->name == v2 && i != j)
        {
          adjVertex e0;
          e0.weight = num;
          e0.v = vertices[j];
          vertices[i]->adj.push_back(e0);

          adjVertex e1;
          e1.weight = num;
          e1.v = vertices[i];
          vertices[j]->adj.push_back(e1);
        }
      }
    }
  }
}

void Graph::addVertex(string name)
{
  bool found = 0;
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == name)
    {
      found = 1;
    }
  }
  if (found == false)
  {
    vertex *v = new vertex;
    v->name = name;
    vertices.push_back(v);
  }
}

void Graph::displayEdges()
{
  int size = vertices.size();
  int size2 = 0;
  for (int i = 0; i < size; i++)
  {
    cout << vertices[i]->name << " --> ";
    size2 = vertices[i]->adj.size();
    for (int j = 0 ; j < size2; j++)
    {
      cout << vertices[i]->adj[j].v->name;
      if (j != size2)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
    cout << endl;
  }
}

void Graph::readFile(string filename)
{
  //Read File and add runs
  string type = "";
  string name = "";
  string line;
  //open file
  ifstream myFile;
  myFile.open(filename);
  //split
  if(myFile.is_open()){
    cout << "File opened" << endl;
    while(getline(myFile, line)){
      stringstream ss(line);
      string field;
      int count = 0;
      while(getline(ss, field, ',')){
        if(count == 0){
          name = field;
        }
        else if(count == 1){
          type = field;
        }
        count++;
      }//end of inner while 
      if(filename == "Vail.txt"){
        addRun(name, type);
      }
      else if (filename == "Breckenridge.txt")
      {
        addRunHash(name, type);
      }
    }//end of outter while
    myFile.close();
  }//end of if file.opened
  else
  {
    cout << "Failed to open file" << endl;
  }
}

void depthFirstTraversalHelper(vertex* t)
{
  int adjSize = t->adj.size();
  t->visited = true;
  cout << t->name << " --> ";
  for ( int i = 0; i < adjSize; i++)
  {
    if (t->adj[i].v->visited == false)
    {
      depthFirstTraversalHelper(t->adj[i].v);
    }
  }
}

void Graph::depthFirstTraversal(string sourceVertex)
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == sourceVertex)
    {
      vertex *t;
      t = vertices[i];
      depthFirstTraversalHelper(t);
      cout << "Done" << endl;
    }
  }
}

bool Graph::graphSearch(string Sname)
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == Sname)
    {
      return true;
    }
  }
  return false;
}

bool Graph::adjSearch(string v1, string v2)
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == v1)
    {
      for (unsigned int j = 0; j < vertices[i]->adj.size(); j++)
      {
        if (vertices[i]->adj[j].v->name == v2)
        {
          return true;
        }        
      }//end of inner for loop
    }
  }//end of outter for loop
  return 0;
}

int Graph::distanceBtw(string v1, string v2)
{
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == v1)
    {
      for (unsigned int j = 0; j < vertices[i]->adj.size(); j++)
      {
        if (vertices[i]->adj[j].v->name == v2)
        {
          return vertices[i]->adj[j].weight;
        }        
      }//end of inner for loop
    }
  }
  return 0;
}

int Graph::DijkstraAlgorithm(string start, string end)
{
  for(unsigned l=0; l<vertices.size(); l++){
      vertices[l]->visited = false;
  } 
  int distance = 0;
  int final = 0;
  vector<vertex*> solvedVectors;
  vertex *vStart;
  vertex *vEnd;
  vertex *solvedV;
  vertex *s;
  for (unsigned int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == start)
    {
      vStart = vertices[i];
      vStart->visited = true;
      vStart->distance = 0;
      solvedVectors.push_back(vertices[i]);
    }
    if (vertices[i]->name == end)
    {
      vEnd = vertices[i];
    }
  }

  while (!vEnd->visited)
  {
    int min = 10000;
    solvedV = NULL;
    for (unsigned int x = 0; x < solvedVectors.size(); x++)
    {
      s = solvedVectors[x];
      for (unsigned int y = 0; y < s->adj.size(); y++)
      {
        if (!s->adj[y].v->visited)
        {
          distance = s->distance + s->adj[y].weight;
          if (distance < min)
          {
            solvedV = s->adj[y].v;
            min = distance;
            solvedV->pred = s;
          }
        }
      }
    }
    final = min;
    solvedV->distance = min;
    solvedV->visited = 1;
    solvedVectors.push_back(solvedV);
  }
  return final;
}

int hashFunction(string name){
    int sum = 0;
    for (int i = 0; i < name.size()-1; i++)
    {
      sum  += int(name[i]);
    }
    sum  = sum%100;
    return sum;
}//end of hashFunction

void Graph::addRunHash(string name, string type)
{
  int i = 0;
  int position = 0;
  position = hashFunction(name); //getting the position
  if (runArray[position] == "")
  {
    runArray[position] = name;
  }
  else if (runArray[position] != "")
  {
    while (runArray[position] != "")
    {
      position++;
      if (position == 100)
      {
        position = 0;
      }
    }
    runArray[position] = name;
  }

}//end of addRunHash

void Graph::addRun(string name, string type){
  vertex* location;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == "Vail"){
      location = vertices[i];
    }
  }//end of for loop
  LLRunNode* top = location->head;
  LLRunNode* LLtemp = new LLRunNode; //crete a Linked List
  //LLtemp->next = NULL;

  if(location->head == NULL){
    location->head = new LLRunNode;
    LLtemp->name = name;
    LLtemp->type = type;
    location->head = LLtemp;
    location->head->next = NULL;
  }
  else{
    LLRunNode* temp = location->head;
    LLRunNode* prev = temp;
    while(temp != NULL){
      prev = temp;
      temp = temp->next;
      if(temp == NULL)
        {
          LLtemp->name = name;
          LLtemp->type = type;
          LLtemp->next = prev->next;
          prev->next = LLtemp;
          return;
        }
    }//end of while 
  } 
}

void Graph::printHash(){
  for (int i = 0; i < 100; i++)
  {
    //cout << print->name << endl;
    cout << runArray[i] << endl;
  }
}//end of printHash func

void Graph::printLL()
{
  vertex* location;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == "Vail"){
      location = vertices[i];
    }
  }//end of for loop
  LLRunNode* print = location->head;
  while(print != NULL)
  {
    cout << print->name << endl;
    print  = print->next;
  }
}// end of printLL func

void Graph::LLSearch(string runName){
  vertex* location;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name == "Vail"){
      location = vertices[i];
    }
  }//end of for loop
  LLRunNode* temp = location->head;
  while(temp != NULL){
    if(temp->name == runName){
      cout << runName << " is a " << temp->type << " in Vail!" << endl << endl;
      return;
    }
    temp = temp->next; //make it walk
  }//end of while loop
  if (temp == NULL)
  {
    cout << runName << " is not a run/lift in Vail" << endl << endl;
  }
}//end of LLSearch func

void Graph::HTSearch(string runName)
{
  string holdType = "";
  int position = 0;
  position = hashFunction(runName);

    string type = "";
    string name = "";
    string line;
    //open file
    ifstream myFile;
    myFile.open("Breckenridge.txt");
    //split
    if(myFile.is_open()){
      while(getline(myFile, line)){
        stringstream ss(line);
        string field;
        int count = 0;
        while(getline(ss, field, ',')){
          if(count == 0){
            name = field;
          }
          else if(count == 1){
            type = field;
            if(runName == name){
              holdType = type;
            }
          }
          count++;
        }//end of inner while 
      }
    }
  auto start = chrono::steady_clock::now();
  if (runArray[position] == runName)
  {
    cout << runName << " is a " << holdType << " in Breckenridge" << endl;
  }

  else
  {
    while (runArray[position] != runName)
    {
      position++;
      if (position == 100)
      {
        position = 0;
      }
    }
    cout << runName << " is a " << holdType << " in Breckenridge" << endl;
  }
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  cout << "Execution time: " << chrono::duration <double, milli> (diff).count() << " ms" << endl << endl;
}