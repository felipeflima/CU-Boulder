void helperDepthFirstTraversal(vertex *n, string sourceVertex){
    n->visited = true;
    cout<< n->name << " --> ";
    for(unsigned int i = 0; i < n->adj.size(); i++){
        if(n->adj[i].v->visited != true){
            helperDepthFirstTraversal(n->adj[i].v, sourceVertex);
        }
    }
}//end of helperDepthFirstTraversal

void Graph:: depthFirstTraversal(string sourceVertex){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == sourceVertex){
            helperDepthFirstTraversal(vertices[i], sourceVertex);
            cout << "Done";
            break;
        }
    }
}//end of depthFirstTraversal func
