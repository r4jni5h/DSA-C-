#include<iostream>
#include<vector>
using namespace std;
class Edge{
public:
    int u;
    int v;
    int wt;
    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt =wt;
    }
};

class Graph{
public:
    int V;
    vector<Edge> edges;
    vector<int> par;
    vector<int> rank;

    Graph(int V){
        this->V = V;
        for(int i=0; i<V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x]= find(par[x]);
    }

    void UnionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);
        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }

    void kruskal(){
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;});
        int minCost = 0;
        int count = 0;

        for(int i=0; i<edges.size() && count < V-1; i++){
            Edge e = edges[i];
            int parU = e.u;
            int parV = e.v;
            if(parU != parV){
                UnionByRank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }
        cout<<"Min Cost : "<<minCost<<endl;
    }


};

int main(){
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.kruskal();

}