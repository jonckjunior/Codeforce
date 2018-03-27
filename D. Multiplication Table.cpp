#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios::sync_with_stdio(false);
    ll n, m, k; cin >> n >> m >> k;
    ll esq = 1, dir = n*m;
    while(esq < dir){
        ll mid = (esq+dir)/2;
        ll kx = 0;
        for(int i = 1; i <= n; i++)
            kx += min(m,mid/i);
        if(kx <= k-1)
            esq = mid+1;
        else
            dir = mid;
    }
    cout << esq << endl;
    return 0;
}
