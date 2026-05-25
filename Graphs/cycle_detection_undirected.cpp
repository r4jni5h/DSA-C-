#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int V){
        this->V=V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0; u<V; u++){
            cout<<u<<" : ";
            list<int> neighbor = l[u];
            for(int v:neighbor){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    bool cycleDetectionHelper(int src, int par, vector<bool> vis){
        vis[src]=true;

        list<int> neighbor = l[src];

        for(int v: neighbor ){
            if(!vis[v]){
                if(cycleDetectionHelper(v,src,vis)){
                    return true;
                }
            }else{
                if(v != par){
                    return true;
                }
            }
        }
        return false;
    }

    bool cycleDetection(){
        vector<bool> vis(V,false);

        return cycleDetectionHelper(0,-1,vis);
    }
};

int main(){
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);

    cout<<graph.cycleDetection()<<endl;


    return 0;
}