#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int pos = 0, res = 0;
    while(pos < n){
        int aux = 1;
        while(pos+1 < n && v[pos+1] > v[pos]){
            aux++;
            pos++;
        }
        pos++;
        res = max(res, aux);
    }
    cout << res << endl;
}
