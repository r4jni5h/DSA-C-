#include<iostream>
#include<string> 
using namespace std;
class Student{
public:
    string name;
    int marks;

    Student(string name,int marks){
        this->name = name;
        this->marks = marks;
    }
    bool operator < (const Student &obj) const {
        return this->marks > obj.marks;
    }
};



int main(){
    priority_queue<Student> pq;
    pq.push(Student("Rajnish",99));
    pq.push(Student("Karan",89));
    pq.push(Student("Venky",79));

    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().marks<<endl;
        pq.pop();

    }
    return 0;
}