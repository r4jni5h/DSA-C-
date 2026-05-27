#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;
public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }
    
    void printAllPathHelper(int src, int dest, vector<bool> vis, string path){
        if(src == dest){
            cout<<path<<dest<<endl;
        }

        vis[src]=true;
        path += to_string(src);

        list<int> neighbor = l[src];
        for(int v: neighbor){
            if(!vis[v]){
                printAllPathHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printAllPath(int src, int dest){
        vector<bool> vis(V, false);
        string path;

        printAllPathHelper(src, dest, vis, path);
    }

    
};

int main(){
    Graph graph(6, false);

    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.printAllPath(5,1);

    return 0;
}