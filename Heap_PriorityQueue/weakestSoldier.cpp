#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k){
    vector<int> ans;
    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i=0; i<mat.size(); i++){
        int count = 0;
        for(int j=0; j<mat[i].size(); j++){
            if(mat[i][j]==1){
                count++;
            }
        }
        pq.push({count,i});
    }
    for(int i=0; i<k; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;

}

int main(){
    vector<vector<int>> mat = {
        {1,0,1,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };
    int k = 3;
    vector<int> ans =kWeakestRows(mat,k);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" "<<endl;
    }
    return 0;
}