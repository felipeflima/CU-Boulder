#include <iostream>

using namespace std;

void setAllVerticesUnvisited(vector<vertex*> vertices){
    unsigned int i;
    for(i=0; i<vertices.size(); i++){
      vertices[i]->visited = false;
    }
}//end ofsetAllVerticesUnvisited func




bool DFTraversalBipartite(vertex* n){
    bool bipartite = true;
    n->visited = true;
    n->color = "red";
    for(unsigned int i = 0; i < n->adj.size(); i++){
        if(n->color == n->adj[i].v->color){
            bipartite = false;
            return bipartite;
        }
        else if(n->adj[i].v->visited != true){
            if(n->color == "red"){
                n->adj[i].v->color = "blue";
            }
            else if(n->color == "blue"){
                n->adj[i].v->color = "red";
            }
            DFTraversalBipartite(n->adj[i].v);
        }
    }
    return bipartite;
}//end of DFTraversalBipartite function

bool Graph::checkBipartite(){
    bool bipartite = true;
    setAllVerticesUnvisited(vertices);
    bipartite = DFTraversalBipartite(vertices[0]);
    if(bipartite == false){
        return bipartite;
    }
    else{
        for(unsigned int x = 0; x < vertices.size(); x++){
            if(vertices[x]->visited == false){
                bipartite = DFTraversalBipartite(vertices[x]);
                if(bipartite == false){
                    return bipartite;
                }
            }
        }
    }
    return bipartite;
}//end of checkBipartite func
