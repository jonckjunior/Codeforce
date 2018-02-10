#include <bits/stdc++.h>
using namespace std;

int adj[105], vis[105];

int comeco, fim;

int solve(int u, int len){
    if(vis[u]){
        fim = u;
        return len;
    }
    vis[u] = 1;
    return solve(adj[u], len+1);
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> adj[i];

    bool found = true;
    int res = 1;
    for(int i = 1; i <= n && found; i++)
        if(!vis[i]){
            comeco = i;
            int len = solve(i, 0);
            if(comeco != fim) found = false;
            //printf("ciclo de tamanho %d com %d\n", len, i);
            if(len%2 == 0) res = res*((len/2)/__gcd(res, len/2));
            else           res = res*(len/__gcd(res, len));
        }
    if(found) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}
