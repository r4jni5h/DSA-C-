#include<iostream>
using namespace std;

void transpose(int mat[][3],int n,int m){

    int mat2[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat2[j][i]=mat[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int mat[2][3]={{11,12,13},{21,22,23}};
    int n=2;
    int m=3;

    transpose(mat,n,m);

    return 0;
}