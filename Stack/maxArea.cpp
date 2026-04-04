#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printArr(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void maxAreaHisto(vector<int> h){
    int n = h.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;
    //next smaller left
    nsl[0] = -1;
    s.push(0);
    for(int i=1; i<n; i++){
        int curr = h[i];
        while(!s.empty() && curr <= h[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
    }
    printArr(nsl);
    //clear stack
    while(!s.empty()){
        s.pop();
    }
    //next small right
    nsr[n-1] = n;
    s.push(n-1);
    for(int i=n-2; i>=0; i--){
        int curr = h[i];
        while(!s.empty() && curr <= h[s.top()] ){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
        
    }
    printArr(nsr);

    int maxArea = 0;

    for(int i=0; i<n; i++){

        int ht = h[i];
        int wdt = nsr[i]-nsl[i]-1;

        int area = ht * wdt ;

        maxArea = max(maxArea,area);
    }
    cout<<maxArea<<endl;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};

    maxAreaHisto(heights);

    return 0;
}