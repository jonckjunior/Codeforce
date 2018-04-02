#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    
    int n, m; cin >> n >> m;
    
    vector<ll> v1,v2;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v1.push_back(x);
    }
    for(int i = 0; i < m; i++){
        ll x; cin >> x;
        v2.push_back(x);
    }
    vector<ll> v;
    for(int i = 0; i < n; i++){
        ll aux = -1e18-5;
        for(int j = 0; j < m; j++)
            aux = max(aux, v1[i] * v2[j]);
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    v.pop_back();
    cout << v.back() << endl;
    return 0;
}
