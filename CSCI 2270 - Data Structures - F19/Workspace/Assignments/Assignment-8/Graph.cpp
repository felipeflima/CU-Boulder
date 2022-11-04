#include "Graph.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

void Graph::addEdge(string v1, string v2)
{
  for (int i = 0; i < vertices.size(); i++)
  {
    if (vertices[i]->name == v1)
    {
      for (int j = 0; j < vertices.size(); j++)
      {
        if (vertices[j]->name == v2 && i != j)
        {
          adjVertex e0;
          e0.v = vertices[j];
          vertices[i]->adj.push_back(e0);

          adjVertex e1;
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

void Graph::breadthFirstTraverse(string sourceVertex)
{
  vertex *vStart;
  int size = vertices.size();

  for(int i = 0; i < size; i++)
  {
      if(vertices[i]->name == sourceVertex)
      {
          vStart = vertices[i];
      }
  }

  vStart->visited = true;
  queue<vertex*> q;

  q.push(vStart);

  vertex *n;
  cout << "Starting vertex (root): " << vStart->name << "-> ";

  int size2;

  while(!q.empty()){

      n = q.front();
      q.pop();

      size2 = n->adj.size();
      for( int x = 0; x < size2; x++ )
      {
          if (n->adj[x].v->visited == false)
          {
            n->adj[x].v->visited = true;
            n->adj[x].v->distance = n->distance+1;
            cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ")" << " ";
            q.push(n->adj[x].v);
          }
      }
  }
}


void getConnectedComponentsHelper(vertex* t)
{
  int adjSize = t->adj.size();
  t->visited = true;
  for ( int i = 0; i < adjSize; i++)
  {
    if (t->adj[i].v->visited == false)
    {
      getConnectedComponentsHelper(t->adj[i].v);
    }
  }
}

int Graph::getConnectedComponents()
{
  int size = vertices.size();
  int sub = 0;
  for (int i = 0; i < size; i++)
  {
    vertices[i]->visited = false;
  }
  getConnectedComponentsHelper(vertices[0]);
  sub++;
  for (int j = 0; j < size; j++)
  {
    if (vertices[j]->visited == false)
    {
      sub++;
      getConnectedComponentsHelper(vertices[j]);
    }
  }
  return sub;
}

bool checkBipartiteHelper(vertex* vStart)
{
  //bool bipartite = true;
  int size2;
  vStart->visited = true;
  vStart->color = "red";

  queue<vertex*> q;
  q.push(vStart);
  vertex *n;

  while(!q.empty())
  {
    n = q.front();
    q.pop();

    size2 = n->adj.size();
    for( int x = 0; x < size2; x++ )
    {
      if ((n->color == n->adj[x].v->color) || ((n->color == n->adj[x].v->color)))
      {
        return false;
      }
      if (n->adj[x].v->visited == false)
      {
        n->adj[x].v->visited = true;
        if (n->color == "red")
        {
          n->adj[x].v->color = "blue";
        }
        if (n->color == "blue")
        {
          n->adj[x].v->color = "red";
        }
        q.push(n->adj[x].v);
      }
    }
  }
return true;

}

bool Graph::checkBipartite()
{
  bool bipartite = true;
  bipartite = checkBipartiteHelper(vertices[0]);
  int size = vertices.size();
  if (bipartite == true)
  {
    for (int j = 0; j < size; j++)
    {
      if (vertices[j]->visited == false)
      {
        bipartite = checkBipartiteHelper(vertices[j]);
      }
    }
  }
  return bipartite;
}
