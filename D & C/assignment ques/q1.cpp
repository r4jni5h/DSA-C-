#include<iostream>
#include<string>
using namespace std;

void merge(string arr[],int si,int ei,int mid ){
    vector<string> temp;
    int i = si;
    int j = mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    for(int i=0;i<temp.size();i++){
        arr[si+i]=temp[i];
    }
}

void mergeSortString(string arr[],int si,int ei){
    if(si >= ei) return;
    
    int mid = si + (ei-si)/2;

    mergeSortString(arr,si,mid);
    mergeSortString(arr,mid+1,ei);

    merge(arr,si, ei, mid);
}

int main(){
    string arr[] = {"sun","earth","mars","mercury"};
    int n = sizeof(arr)/sizeof(string);

    mergeSortString(arr,0,n-1);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}