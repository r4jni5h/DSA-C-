#include<iostream>
using namespace std;

bool duplication(int nums[],int n){
    int a=nums[0];
    for(int i=1;i<n;i++){
        if(a==nums[i]){
            return true;
        }else{
            a=nums[i];
        }
    }
    return false;

}

int main(){
    int nums[]={1,2,3,3,4,5};
    int n = sizeof(nums)/sizeof(int);

    cout<<duplication(nums,n);

    return 0;
}