#include<iostream>
using namespace std;

void binToDec(int binNum){
    int n = binNum;
    int pow = 1;
    int decNum=0;

    while(n>0){
        int lastDig = n % 10;
        decNum += lastDig * pow;
        pow=pow*2;
        n = n/10;
    }
    cout<<"Decimal Number of "<<n<<"is "<<decNum<<endl;

}

void decToBin(int decNum){
    int n = decNum;
    int pow=1;
    int binNum=0;

    while(n>0){
        int rem =n % 2;
        binNum += rem * pow;
        pow=pow*10;
        n=n/2;
    }
    cout<<"Binary Number of "<<n<<" is " <<binNum<<endl;
}

int main(){
    cout<<"Binary to Decimal"<<endl;
    binToDec(111111);
    binToDec(10110);
    binToDec(10011);
    binToDec(110010);
    cout<<"Decimal to Binary"<<endl;
    decToBin(25);
    decToBin(49);
    decToBin(31);
    decToBin(88);


}