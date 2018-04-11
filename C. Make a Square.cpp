#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n; cin >> n;
    vector<ll> v;
    for(ll i = 1; i <= sqrt(n); i++)
        v.push_back(i*i);
    string s = to_string(n);
    int k = 1e9, len = s.size();
    for(int i = 1; i <= (1 << len) - 1; i++){
        string aux = "";
        for(int j = 0; j < len; j++)
            if( (1 << j)&i )
                aux += s[j];
        if(aux.size() == 0) continue;
        int weiss = stoi(aux);
        string nova = to_string(weiss);
        if(nova.size() != aux.size()) continue;
        if(binary_search(v.begin(), v.end(), weiss))
            k = min(k, (int)s.size() - (int)aux.size());
    }
    if(k == 1e9) cout << -1 << endl;
    else cout << k << endl;
    return 0;
}
