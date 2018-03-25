#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> v;

int main(){
    ll a, b, f, k; cin >> a >> b >> f >> k;

    v.push_back(f);
    ll turn = k;
    while(k > 0){
        if(k == 1)
            v.push_back((a-f));
        else
            v.push_back((a-f)*2);
        k--;
        if(k == 0) break;
        
        if(k == 1)
            v.push_back(f);
        else
            v.push_back(2*f);
        k--;
    }
    if(turn == 1 && max(a-f, f) > b){
        cout << -1 << endl;
        return 0;
    }
    if(turn == 2 && max((a-f)*2, f) > b){
        cout << -1 << endl;
        return 0;
    }
    if(turn > 2 && max((a-f)*2, f*2) > b){
        cout << -1 << endl;
        return 0;
    }

    int n = v.size();
    
    ll res = 0, pos = 0;
    while(pos < n){
        int sum = 0;
        while(pos < n && v[pos]+sum <= b)
            sum += v[pos++];
        if(pos != n)
            res++;
            
    }
    cout << res << endl;
    return 0;
}
