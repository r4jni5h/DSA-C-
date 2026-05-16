#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<string> printIternary(vector<vector<string>> tickets){
    vector<string> ans;
    unordered_map<string,string> m;
    for(int i=0;i<tickets.size(); i++){
        string from = tickets[i][0];
        string to = tickets[i][1];
        m[from] = to;
    }

    unordered_set<string> to;
    for(pair<string,string> s:m){
        to.insert(s.second);
    }
    string start="";
    for(pair<string,string> ticket: m){
        if(to.find(ticket.first)==to.end()){
            start = ticket.first;
        }
    }

    ans.push_back(start);
    while(m.count(start)){
        start= m[start];
        ans.push_back(start);
    }

    return ans;
}


int main(){
    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};

    vector<string> str = printIternary(tickets);

    for(int i=0; i<str.size(); i++){
        cout<<str[i]<<"->";
    }

    return 0;
}