#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
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

    void topoSortHelper(int src, vector<bool>& vis, stack<int>& s){
        vis[src]=true;
        list<int> neighbor = l[src];
        for(int v : neighbor){
            if(!vis[v]){
                topoSortHelper(v, vis, s);
            }
        }
        s.push(src);
    }

    void topoSort(){
        stack<int> s;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoSortHelper(i, vis, s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    void clacInDegree(vector<int>& inDegree){
        for(int i=0; i<V; i++){
            list<int> neighbor = l[i];
            for(int v: neighbor){
                inDegree[v]++;
            }
        }
    }

    void topoSort2(){
        vector<int> inDegree(V, 0);
        clacInDegree(inDegree);
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int>neighbor = l[curr];
            for(int v : neighbor){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,1);
    graph.addEdge(4,0);

    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort2();

    return 0;
}