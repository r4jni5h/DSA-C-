#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    string name;
    int age;

};
class Student : public Person {
public:
    int studentID;
    Student(string name,int age,int studentID){
        this->name=name;
        this->age=age;
        this->studentID=studentID;
    }
    void displayStudentInfo(){
        cout<<"Name :"<<name<<endl;
        cout<<"Age :"<<age<<endl;
        cout<<"Id :"<<studentID<<endl;
    }
};

int main(){

    Student s1("Rajnish",20,456);
    Student s2("Karan",20,987);
    Student s3("Purab",20,287);
    Student s4("Krishna",20,021);


    s1.displayStudentInfo();
    s2.displayStudentInfo();
    s2.displayStudentInfo();
    s3.displayStudentInfo();

    return 0;
}