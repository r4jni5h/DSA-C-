#include<iostream>
using namespace std;

int all7s(int mat[][3],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==7){
                sum++;
            }
        }
    }
    return sum;
} 

int main(){
    int mat[][3]={{4,7,8},{8,7,7}};
    int n=2;
    int m=3;

    cout<<all7s(mat,n,m)<<endl;
}