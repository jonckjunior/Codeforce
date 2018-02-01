#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 1e7;
int bt[maxn+5], cnt[maxn+5], v[maxn+5], f[maxn+5], sum[maxn+5];

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    
    for(int i = 2; i <= maxn; i++)
        bt[i] = 1;
    
    for(ll i = 2; i <= maxn; i++){
        if(bt[i]){
            f[i] = cnt[i];
            for(ll j = i+i; j <= maxn; j += i){
                bt[j] = 0;
                f[i] += cnt[j];
            }
        }
        sum[i] = sum[i-1] + f[i];
    }
    
    int m; cin >> m;
    
    for(int i = 0; i < m; i++){
        int esq, dir; cin >> esq >> dir;
        if(dir > maxn) dir = maxn;
        if(esq > maxn) esq = maxn;
        cout << sum[dir] - sum[esq-1] << endl;
    }
    
    
    
    return 0;
}
