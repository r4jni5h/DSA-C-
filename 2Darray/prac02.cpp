#include<iostream>
using namespace std;

int secondRowSum(int mat[][3],int n,int m){
    int secRowSum=0;
    for(int i=0;i<m;i++){
        secRowSum+=mat[1][i];
    }
    return secRowSum;
}

int main(){
    int arr[][3]={{1,4,9},{11,4,3},{2,2,3}};
    int n=3,m=3;

    cout<<secondRowSum(arr,n,m)<<endl;

    return 0;
}