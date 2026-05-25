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

    
    void dfsHelper(int u, vector<bool>& vis){
        vis[u] = true;
        cout<<u<<" ";

        list<int> neighbhor = l[u];
        for(int v: neighbhor){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsHelper(i, vis);
                cout<<endl;
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph graph(10);

    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,7);
    graph.addEdge(3,8);
    graph.addEdge(2,5);
    graph.addEdge(2,0);

    graph.dfs();

    return 0;
}