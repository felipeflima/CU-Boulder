void Tree::preOrderTraverse(Node *node){
  if (node == NULL)
        return;
    cout << node->data << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}

void Tree::deleteTree(Node *node){
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    cout<<"\n Deleting node:"<< node->data;
    delete node;
}

Node* BST:: addNodeHelper(Node* currNode, int data){
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;
}

void BST:: addNode(int data){
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

void Graph::addEdge(int v1, int v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->key == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
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
      for( int x = 0; x < size2; x++ ){
          if (n->adj[x].v->visited == false){
            n->adj[x].v->visited = true;
            n->adj[x].v->distance = n->distance+1;
            cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ")" << " ";
            q.push(n->adj[x].v);
          }
      }
  }
}

void depthFirstTraversalHelper(vertex* t)
{
  int adjSize = t->adj.size();
  t->visited = true;
  cout << t->name << " --> ";
  for ( int i = 0; i < adjSize; i++){
    if (t->adj[i].v->visited == false){
      depthFirstTraversalHelper(t->adj[i].v);
    }
  }
}


void Graph::depthFirstTraversal(string sourceVertex)
{
  for (unsigned int i = 0; i < vertices.size(); i++){
    if (vertices[i]->name == sourceVertex){
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
  for (unsigned int i = 0; i < vertices.size(); i++){
    if (vertices[i]->name == start){
      vStart = vertices[i];
      vStart->visited = true;
      vStart->distance = 0;
      solvedVectors.push_back(vertices[i]);
    }
    if (vertices[i]->name == end){
      vEnd = vertices[i];
    }
  }
  while (!vEnd->visited)
  {
    int min = 10000;
    solvedV = NULL;
    for (unsigned int x = 0; x < solvedVectors.size(); x++){
      s = solvedVectors[x];
      for (unsigned int y = 0; y < s->adj.size(); y++){
        if (!s->adj[y].v->visited){
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
