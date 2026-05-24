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
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0; u<V; u++){
            list<int> neighbhor = l[u];
            cout<<u<<": ";
            for(int v: neighbhor){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(V,false);

        q.push(0);
        vis[0]=true;

        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            list<int> neighbhor = l[u];
            for(int v: neighbhor){
                if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
            }
        }
        cout<<endl;
    }


    bool hasPath(int src, int dest){
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(src);
        vis[src]=true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            if(u==dest){
                return true;
            }
            list<int> neighbor = l[u];
            for(int v: neighbor){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }

        }
        return false;
    }
};

int main(){
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(4,5);
    graph.addEdge(3,5);
    graph.addEdge(5,6);

    cout<<graph.hasPath(0,6)<<endl;

    return 0;
}