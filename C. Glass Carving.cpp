#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios::sync_with_stdio(false);
    ll n, m, t; cin >> m >> n >> t;
    set<ll> x, y;
    vector<pair<char, int> > v;

    for(int i = 0; i < t; i++){
        string s; cin >> s;
        ll k; cin >> k;
        if(s == "H"){
            x.insert(k);
        }
        else{
            y.insert(k);
        }    
        v.push_back({s[0], k});
    }
    x.insert(0); x.insert(n);
    y.insert(0); y.insert(m);

    ll hx = 0, hy = 0;
    for(auto it = x.begin(); it != x.end(); it++){
        auto it2 =(++it)--;
        if(it2 != x.end()){
            hx = max(hx, *it2 - *it);
        }
    }
    for(auto it = y.begin(); it != y.end(); it++){
        auto it2 = (++it)--;
        if(it2 != y.end()){
            hy = max(hy, *it2 - *it);
        }
    }
    ll ress = hx * hy;
    vector<ll> res {ress};
    for (int i = (int)v.size() - 1;  i >= 0; --i){
        char c = v[i].first;
        int k = v[i].second;
        if (c == 'H'){
            auto it = x.find(k);
            auto it_esq = --it;it++;
            auto it_dir = ++it;it--;
            hx = max(hx, *it_dir - *it_esq);
            x.erase(it);
        }
        else{
            auto it = y.find(k);
            auto it_esq = --it;it++;
            auto it_dir = ++it;it--;
            hy = max(hy, *it_dir - *it_esq);
            y.erase(it);
        }
        res.push_back(hx*hy);
    }
    res.pop_back();
    reverse(res.begin(), res.end());
    for(ll val : res)
        cout << val << endl; 
    return 0;
}
