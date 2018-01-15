#include <bits/stdc++.h>
using namespace std;

int esq[100005], dir[100005];
vector<int> v;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        esq[i] = dir[i] = 1;
    }
    int res = 1;
    for(int i = 1; i < n; i++){
        if(v[i] > v[i-1]) esq[i] = esq[i-1]+1;
        res = max(res, esq[i]);
    }
    for(int i = n-2; i >= 0; i--){
        if(v[i] < v[i+1]) dir[i] = dir[i+1]+1;
        res = max(res, dir[i]);
    }

    if(n >= 2){
        res = max(res, 1 + dir[1]);
        res = max(res, 1 + esq[n-2]);
    }

    for(int i = 0; i < n; i++)
        if(i-1 >= 0 && i+1 < n){
            if(v[i-1] + 1 < v[i+1])
                res = max(res, esq[i-1]+1+dir[i+1]);
            res = max(res, esq[i-1]+1);
            res = max(res, 1+dir[i+1]);
        }
    cout << res << endl;
}
