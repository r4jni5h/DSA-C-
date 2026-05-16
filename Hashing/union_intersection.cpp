#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void printUnion(vector<int> nums1, vector<int> nums2){
    unordered_set<int> s;
    for(int i=0; i<nums1.size(); i++){
        s.insert(nums1[i]);
    }
    for(int i=0; i<nums2.size(); i++){
        s.insert(nums2[i]);
    }
    for(int i:s){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printIntersection(vector<int> nums1, vector<int> nums2){
    unordered_set<int> s;
    for(int i=0; i<nums1.size();i++){
        s.insert(nums1[i]);
    }
    for(int i=0; i<nums2.size(); i++){
        if(s.count(nums2[i])){
            cout<<nums2[i]<<" ";
            s.erase(nums2[i]);
        }
    }
    cout<<endl;
}

int main(){
    vector<int> nums1={7,3,9};
    vector<int> nums2={6,3,9,2,9,4};

    printUnion(nums1,nums2);
    printIntersection(nums1,nums2);
    
    return 0;
}