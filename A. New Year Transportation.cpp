#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t; cin >> n >> t;
    t--;
    vector<int> v;
    for(int i = 0; i < n-1; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    v.push_back(-1);
    int pos;
    for(pos = 0; v[pos] != -1 && pos != t; pos += v[pos]);
    if(pos == t) cout << "YES" << endl;
    else cout << "NO" << endl;
}
