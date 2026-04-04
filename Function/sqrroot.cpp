#include<iostream>
using namespace std;

int square(int n){

    return n*n;
}

int sqrRoot(int a,int b){

    int x = square(a);
    int y = square(b);
    int z = 2*(a*b);

    return x+y+z;

}



int main(){
    int a,b;
    cout<<"Enter the A :";
    cin>>a;
    cout<<"Enter the B :";
    cin>>b;

    cout<<sqrRoot(a,b)<<endl;


    return 0;
}