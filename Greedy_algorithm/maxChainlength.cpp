#include<iostream>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

void maxChainLenght(vector<pair<int,int>> pr){
    int n = pr.size();

    sort(pr.begin(),pr.end(),compare);
    int ans=1;
    int currEnd = pr[0].second;

    for(int i=1; i<n; i++){
        if(pr[i].first>=currEnd){
            ans++;
            currEnd = pr[i].second;
        }
    }
    cout<<"Max Chain is "<<ans<<endl;
}

int main(){
    int n = 5;
    vector<pair<int,int>> p(5, make_pair(0,0));

    p[0] = make_pair(5,24);
    p[1] = make_pair(39,60);
    p[2] = make_pair(5,28);
    p[3] = make_pair(27,40);
    p[4] = make_pair(50,90);

    maxChainLenght(p);

    return 0;
}