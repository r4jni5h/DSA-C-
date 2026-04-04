#include<iostream>
using namespace std;
//bruteforce 
void Search(int arr[][4],int n,int m,int key){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){
                cout<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }
}
//binarySearch

void Search2(int arr[][4],int n, int m,int key){
    for(int i=0;i<n;i++){
        int st=0;
        int end=m-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[i][mid]==key){
                cout<<"("<<i<<","<<mid<<")"<<endl;
                return;
            }else if(key > arr[i][mid]){
               st=mid+1; 
            }else{
                end=mid-1;
            }
        }
    }
    cout << "Element not found" << endl;
}


//staircaseSearch
bool Search3(int arr[][4],int n,int m,int key){
    int i = 0;
    int j = m-1;

    while( i<n && j>=0 ){
        int cell = arr[i][j];
        if(key==cell){
            cout<<"("<<i<<","<<j<<")"<<endl;
            return true;
        }else if(cell>key){
            j--;
        }else{
            i++;
        }
    }
    cout << "Element not found" << endl;
    return false;
}

int main(){
    int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};

    Search(arr,4,4,50 );
    Search2(arr,4,4,50 );
    Search3(arr,4,4,50 );

    return 0;
}