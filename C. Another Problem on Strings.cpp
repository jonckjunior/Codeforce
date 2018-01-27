#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cnt[1000005];

int main(){
    
    ll k; cin >> k;
    string s; cin >> s;
    s = "!" + s;
    ll len = s.size();
    for(ll i = 1; i < len; i++){
        cnt[i] = cnt[i-1] + (s[i] == '1');
        //printf("cnt[%d] = %d\n", i, cnt[i]);
    }
    
    ll res = 0;
    for(ll i = 1; i < len; i++){
        ll esq = i, dir = len-1, resDir = -1;
        while(esq <= dir){
            ll mid = (esq+dir)/2;
            ll aux = cnt[mid] - cnt[i-1];
            if(aux <= k){
                esq = mid+1;
                if(aux == k)
                    resDir = max(resDir, mid);
            }
            else
                dir = mid-1;
        }
        
        if(resDir == -1) continue;
        
        esq = i, dir = len-1;
        ll resEsq = 1e9;
        
        while(esq <= dir){
            ll mid = (esq+dir)/2;
            ll aux = cnt[mid] - cnt[i-1];
            if(aux >= k){
                dir = mid - 1;
                if(aux == k)
                    resEsq = min(resEsq, mid);
            }
            else
                esq = mid+1;
        }
        //printf("%d achou resdir = %d, e resEsq = %d\n", i, resDir, resEsq);
        res += resDir-resEsq+1;
    }
    cout << res << endl;
    return 0;
}
