#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
using namespace std;

int countDistinct(vector<int> nums){
    set<int> s;
    for(int i=0; i<nums.size(); i++){
        s.insert(nums[i]);
    }
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    return s.size();
}

int main(){
    vector<int> nums={9,1,2,4,2,3,5,7,2,3,5};
    cout<<countDistinct(nums)<<endl;
}