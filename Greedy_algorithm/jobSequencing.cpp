#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int,int>p1, pair<int,int>p2){
    return p1.second > p2.second;
}

int maxSequencing(vector<pair<int,int>> jobs){
    sort(jobs.begin(),jobs.end(),compare);
    int ans = jobs[0].second;
    int last = jobs[0].first;
    for(int i=1; i<jobs.size(); i++){
        if(jobs[i].first > last){
            ans += jobs[i].second;
            last++;
        }
    }
    return ans;
}

int main(){
    vector<pair<int,int>> jobs(4,make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    cout<<maxSequencing(jobs);


    return 0;
}