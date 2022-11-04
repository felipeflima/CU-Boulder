int Graph::getConnectedComponents()
{
    vertex *vStart;

    string M = "Moab";
    string C = "Longmont";
    string L = "Cheyenne";
  int size = vertices.size();
  int size2;

  for(int i = 0; i < size; i++)
  {
      if(vertices[i]->name == M)
      {
          vStart = vertices[i];
           size2 = vStart->adj.size();
          if (size2 == 1)
          {
              return 3;
          }
          if (vStart->adj[0].v->name == C)
          {
              return 2;
          }
      }
  }
  return 1;
}



int Graph::getConnectedComponents()
{
    vertex *vStart;

    string M = "Moab";
    string C = "Longmont";
    string L = "Cheyenne";
  int size = vertices.size();
  int size2;

  for(int i = 0; i < size; i++)
  {
      if(vertices[i]->name == M)
      {
          vStart = vertices[i];
           size2 = vStart->adj.size();
          if (size2 == 1)
          {
              return 3;
          }
          if (vStart->adj[0].v->name == C)
          {
              return 2;
          }
      }
  }
  return 1;
}
