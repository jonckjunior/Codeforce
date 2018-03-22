#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f[100005];

string f0, p1, p2, p3;

char solve(ll n, ll k){
    if(n == 0)
        return (k < f0.size() ? f0[k] : '.');
    if(k < p1.size())
        return p1[k];
    k -= p1.size();
    if(k < f[n-1])
        return solve(n-1, k);
    k -= f[n-1];
    if(k < p2.size())
        return p2[k];
    k -= p2.size();
    if(k < f[n-1])
        return solve(n-1, k);
    k -= f[n-1];
    if(k < p3.size())
        return p3[k];
    return '.';
}

int main(){
    f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    p1 = "What are you doing while sending \"";
    p2 = "\"? Are you busy? Will you send \"";
    p3 = "\"?";
    f[0] = f0.size();
    for(int i = 1; i <= 100001; i++){
        if(f[i-1] >= 1e18)
            f[i] = 1e18+5;
        else
            f[i] = f[i-1]*2 + 68;
    }
    int t; cin >> t;
    for(int caso = 0; caso < t; caso++){
        ll n, k; cin >> n >> k;
        k--;
        cout << solve(n, k);
    }
    cout << endl;
    return 0;
}
