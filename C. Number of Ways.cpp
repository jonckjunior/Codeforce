#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    vector<int> v;
    ll n; cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
        sum += x;
    }
    if(sum%3 != 0){
        cout << 0 << endl;
    }
    else{
        ll s1 = sum/3;
        ll s2 = s1*2;
        sum = 0;
        vector<int> v1,v2;
        for(int i = 0; i < n-1; i++){
            sum += v[i];
            if(sum == s1) v1.push_back(i);
            if(sum == s2) v2.push_back(i);
        }
        ll res = 0;
        for(int i = 0; i < (int)v1.size(); i++)
            res += v2.end()-upper_bound(v2.begin(), v2.end(), v1[i]);
        cout << res << endl;
    }
}
