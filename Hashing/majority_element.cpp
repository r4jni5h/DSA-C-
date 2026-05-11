#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void majorityElement(vector<int> nums){
    int n= nums.size();
    unordered_map<int,int> m;

    for(int i=0; i<n; i++){
        if(m.count(nums[i])){
            m[nums[i]]++;
        }else{
            m[nums[i]]=1;
        }
    }
    for(pair<int,int> p:m){
        if(p.second>n/3){
            cout<<p.first<<" ";
        }
    }

}

int main(){
    vector<int> nums={1,2};
    majorityElement(nums);

    return 0;
}