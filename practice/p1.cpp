#include<iostream>
using namespace std;

class BankAccount{
    int accountNumber;
    int balance=0;
public:
    void deposit(){
        int money;
        cout<<"Enter Amount(for deposite) : ";
        cin>>money;
        balance = balance + money;
        cout<<"Deposite :"<<money<<endl;
        cout<<"Your Balance is :"<<balance<<endl;
    }
    void withdraw(){
        int money;
        cout<<"Enter Amount(for withdraw) : ";
        cin>>money;
        balance = balance - money;
        cout<<"withdraw :"<<money<<endl;
        cout<<"Your Balance is :"<<balance<<endl;
    }
    void getBalance(){
        cout<<"Your Balance is :"<<balance<<endl;
    }
};

int main(){
    BankAccount p1;
    p1.deposit();

    p1.withdraw();

    p1.getBalance();

    return 0;    
}