#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct ComparePair {
    bool operator()(pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second < p2.second;   // Higher marks get higher priority
    }
};

int main() {
    priority_queue<
        pair<string, int>,
        vector<pair<string, int>>,
        ComparePair
    > pq;

    pq.push(make_pair("Rajnish", 99));
    pq.push(make_pair("Karan", 89));
    pq.push(make_pair("Venky", 79));

    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}