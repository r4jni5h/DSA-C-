#include<iostream>
#include <vector>
using namespace std;

vector<int> findCommonElements(vector<int> a, vector<int> b, vector<int> c){
        //Write your code here   
        vector<int> ans;
        for(int i=0;i<a.size();i++){
            int a_b_comm = 0;
            int st = 0;
            int end = b.size()-1;
            while(st <= end){
                int mid = (st + end)/2;
                if(b[mid]==a[i]){
                    a_b_comm = b[mid];
                }
                if(b[mid]<a[i]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
            for(int j=0;j<c.size();j++){
                if(a_b_comm == c[j]){
                    ans.push_back(c[j]);
                }
            }
            
        }

        return ans;    
    }

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin >> b[i];
    }
    vector<int> c(k);
    for(int i=0;i<k;i++) {
        cin >> c[i];
    }
    vector<int> ans = findCommonElements(a,b,c);
    n = ans.size();
    if(n == 0) {
        cout << -1 << endl;
    }
    else {
        for(int i=0;i<n;i++) {
            if(i == n-1) {
                cout << ans[i] << endl;
            }
            else {
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}