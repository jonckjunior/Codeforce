#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dfs(ll n){
    if(n <= 1) return 1;
    else{
        ll esq = dfs(n/2);
        esq *= 2;
        esq++;
        return esq;
    }
}

ll solve(ll esq, ll dir, ll n, ll L, ll R){
    if(esq > R || dir < L || n == 0) return 0;
    if(esq >= L && dir <= R) return n;
    ll mid = (esq+dir)/2;
    ll res = solve(esq, mid-1, n/2, L, R) + solve(mid+1, dir, n/2, L, R);
    if(mid >= L && mid <= R)
        res += n%2;
    return res;
}

int main(){
    ll n, l, r; cin >> n >> l >> r;
    ll len = dfs(n);
    cout << solve(1, len, n, l, r) << endl;
    return 0;
}
