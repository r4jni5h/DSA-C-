#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) { 
    int arr[10]= {0};
    int n = grid.size();
    int size = n*n;
    vector<int>freq(size,0);
    vector<int>ans;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            freq[grid[i][j]-1]++;
        }
    }
    return freq;
}

int main(){
    vector<vector<int>>grid = {{9,1,7},{8,9,2},{3,4,6}};

    vector<int> ans=findMissingAndRepeatedValues(grid);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }

    return 0;
}