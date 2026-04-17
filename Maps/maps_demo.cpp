#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> m;

    m[111]="Rajnish";
    m[110]="Karan";
    m[112]="Vyank";

    for(auto it:m){
        cout<<"Key :" <<it.first<<", "<<"Value :"<<it.second<<endl;
    }



    return 0;
}