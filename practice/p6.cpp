#include<iostream>

using namespace std;

void occerence(int arr[],int key,int i,int n){
    if(i == n ){
        return;
    }
    if(arr[i]==key){
        cout<<i<<" ";
        occerence(arr,key,i+1,n);
    }else{
        occerence(arr,key,i+1,n);
    }
}

int main(){
    int arr[]={3,2,4,5,6,2,7,2,2};
    int n = sizeof(arr)/sizeof(int);
    int key=2;

    occerence(arr,key,0,n);

    return 0;

}