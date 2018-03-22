#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/* Canto do Felipera
    
*/

const int maxn = 2e5+5; 

int p[maxn], vis[maxn], depth[maxn], low[maxn];
int magia = 1e9 + 7;

vector<int> comp, S;
int k;

ll modpow(ll base, ll exp){
    if(exp == 0)
        return 1LL;
    if(exp == 1)
        return base;
    ll aux = modpow(base, exp/2);
    aux = (aux*aux)%magia;
    if (exp % 2 != 0)
        aux = (aux * base)%magia;
    return aux;
}

void dfs(int cur) {
    depth[cur] = low[cur] = ++k;
    S.push_back(cur);
    vis[cur] = 1;
    
    if (vis[p[cur]] == 0)
        dfs(p[cur]);
    if (vis[p[cur]] == 1)
        low[cur] = min(low[p[cur]], low[cur]);
    if (low[cur] == depth[cur]) {
        int aux = 1;
        while (S.back() != cur){
            int x = S.back(); S.pop_back();
            vis[x] = 2; 
            ++aux;
        }
        vis[S.back()] = 2; 
        S.pop_back();
        comp.push_back(aux);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        if(vis[i] == 0)
            dfs(i);
    int numComp = 0, weiss = 0;
    ll res = 1;
    for(int val : comp){
        if(val >= 2)
            res = (res * (modpow(2, val)-2) )%magia;
        else
            res = (res * modpow(2, val))%magia;
    }
    cout << res << endl;
    // deu ruim
    //cout << (modpow(2LL, n) - modpow(2LL, weiss)) << endl;
    return EXIT_SUCCESS;
}
