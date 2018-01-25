#include <bits/stdc++.h>
using namespace std;

vector<int> v,v1,v2;

int main() {
    ios::sync_with_stdio(false);
    int n, t; cin >> n >> t;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int esq=0,dir=0,res=(v[0] <= t),sum=v[0];
    while(dir < n){
        while(dir+1 < n && v[dir+1]+sum <= t){
            sum += v[dir+1];
            dir++;
            res = max(res, dir-esq+1);
        }
        dir++;
        if(dir >= n) break;
        sum += v[dir];
        while(esq <= dir && sum > t){
            sum -= v[esq];
            esq++;
        }
    }
    cout << res << endl;
}
