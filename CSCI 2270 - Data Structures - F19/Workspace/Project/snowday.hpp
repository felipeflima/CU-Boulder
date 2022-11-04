#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct LLRunNode{
    string name;
    string type;
    struct LLRunNode* next;   // Pointer to the next node

    LLRunNode(){}

    LLRunNode(string n, string t) : name(n), type(t), next(NULL) {}
};

struct Hash{
    LLRunNode* top = NULL;
};

struct vertex;
struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    vertex() {
        this->visited = false;
        this->distance = 0;
        this ->pred = NULL;
    }
    string name;
    string type;
    bool visited;
    int distance;
    vertex *pred;
    vector<adjVertex> adj;
    LLRunNode* head = NULL;
};


class Graph
{
    public:
        void addEdge(string v1, string v2, int num);
        void addVertex(string name);
        void displayEdges();
        void depthFirstTraversal(string sourceVertex);
        int DijkstraAlgorithm(string start, string end);
        bool graphSearch(string Sname);
        bool adjSearch(string v1, string v2);
        int distanceBtw(string v1, string v2);
        void addRunHash(string name, string type);
        void addRun(string name, string type);
        void printHash();
        void printLL();    
        void readFile(string filename);    
        void LLSearch(string runName);
        void HTSearch(string runName);


    private:
        vector<vertex*> vertices;
        string runArray[100];
};

#endif // GRAPH_H
