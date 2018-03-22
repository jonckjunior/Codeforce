#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/* Canto nosso

Considerando que cada nó tem um pai
ou o componente é ele mesmo (auto loop)
ou todo mundo é um componente
escolhe os dois maiores e xablau
*/

int p[100005], vis[100005];
vector<ll> aux;

int solve(int u){
    vis[u] = 1;
    int res = 1;
    if(!vis[p[u]])
        res += solve(p[u]);
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    ll res = 0;
    
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            int weiss = solve(i);
            aux.push_back(weiss);
        }
    sort(aux.rbegin(), aux.rend());
    if(aux.size() == 1)
        res = aux[0]*aux[0];
    else{
        res = aux[0]+aux[1];
        res *= res;
        for(int i = 2; i < (int)aux.size(); i++)
            res += aux[i]*aux[i];
    }
    cout << res << endl;
    return 0;
}
