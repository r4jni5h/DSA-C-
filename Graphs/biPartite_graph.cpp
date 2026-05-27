#include<iostream>
#include<vector>
#include<string>
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
            list<int> neighbor = l[u];
            cout<<u<<" :";
            for(int v: neighbor){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    bool isBipartite(){
        vector<int> color(V,-1);
        queue<int> q;
        q.push(0);
        color[0]=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            list<int> neighbor = l[curr];
            for(int v: neighbor){
                if(color[v] == -1){
                    color[v] = !color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        } 
        return true;
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    // graph.addEdge(0,3);
    
    cout<<graph.isBipartite()<<endl;
    return 0;
}