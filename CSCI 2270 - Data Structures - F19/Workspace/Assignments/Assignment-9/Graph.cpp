#include "Graph.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

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

vertex* Graph::DijkstraAlgorithm(string start, string end)
{
  int distance;
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
  //vStart.solved = true;

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
    solvedV->distance = min;
    solvedV->visited = 1;
    solvedVectors.push_back(solvedV);
  }

  return vEnd;
}

void Graph::shortestpath(string start, string end)
{
  vector<vertex*> path;
  vertex *crawler;
  int size = vertices.size();

  for (int i = 0; i < size; i++)
  {
    if (end == vertices[i]->name)
    {
      crawler = vertices[i];
    }
  }

  while(crawler != NULL)
  {
      path.push_back(crawler);
      crawler = crawler->pred;
  }

  for (unsigned int j = 0; j < path.size(); j++)
  {
    cout << path[path.size()-1-j]->name << " ";
  }

}
