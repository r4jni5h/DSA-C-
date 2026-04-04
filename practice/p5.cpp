#include<iostream>
using namespace std;
int binSearch(int arr[],int st,int end,int key){
    if(st>end){
        return -1;
    }
    int mid = st + (end - st) / 2;
    if(arr[mid]==key){
        return mid;
    }
    if(key>arr[mid]){
        return binSearch(arr,mid+1,end,key);
    }else{
        return binSearch( arr,st,mid-1,key);
    }

}
int main(){

    int arr[]={1,2,3,4,5,6,7};
    cout<<binSearch(arr,0,6,7)<<endl;
}