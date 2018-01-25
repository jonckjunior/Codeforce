#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int esq=0,dir=0,res=0;
    multiset<int> ms;
    while(dir < n){
        ms.insert(v[dir++]);
        while(*ms.rbegin()-*ms.begin() > 1) ms.erase(ms.find(v[esq++]));
        res = max(res, (int)ms.size());
    }
    cout << res << endl;
}
