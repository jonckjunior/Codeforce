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
    int p1=0,p2=0,t=0,esq=0,dir=n-1;
    for(int i = 0; i < n; i++){
        if(t == 0){
            if(v[esq] > v[dir]) p1 += v[esq++];
            else                p1 += v[dir--];
        }
        else{
            if(v[esq] > v[dir]) p2 += v[esq++];
            else                p2 += v[dir--];
        }
        t = !t;
    }
    cout << p1 << " " << p2 << endl;
    return 0;
}
