#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    
    multiset<int> s;
    
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        s.insert(x);
    }
    int res = n;
    for(int i = 0; i < n; i++){
        int x = v[i];
        auto it = lower_bound(s.begin(), s.end(), x);
        if(it != s.end() && *it >= x){
            res--;
            s.erase(it);
        }
    }
    cout << res << endl;
    return 0;
}
