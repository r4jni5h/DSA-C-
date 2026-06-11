#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>>* l;
    bool isUndir;
public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v, wt));
        if(isUndir){
            l[v].push_back(make_pair(u, wt));
        }
    }

    void prism(int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        vector<bool> mst(V, false);
        
        pq.push({0, src});
        int ans = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans+= wt;
                for(pair<int, int> n : l[u]){
                    pq.push({n.second, n.first});
                }
            }
        }
        cout<<"MST : "<<ans<<endl;
    }
};

int main(){
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);

    graph.addEdge(1, 3, 40);

    graph.addEdge(2, 3, 50);
    
    graph.prism(0);

    return 0;
}