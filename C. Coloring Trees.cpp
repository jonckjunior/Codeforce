#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll color[105], cost[105][105], n, m, k;
ll dp[105][105][105];

ll solve(int tree, int group, int lastColor){
    if(tree > n)
        return (group == k ? 0 : 1e15);
    if(dp[tree][group][lastColor] != -1) return dp[tree][group][lastColor];
    ll res = 1e15;
    if(color[tree] == 0){
        for(int c = 1; c <= m; c++){
            ll aux = solve(tree+1, group + (c != lastColor), c) + cost[tree][c];
            res = min(res, aux);
        }
    }
    else
        res = solve(tree+1, group + (color[tree] != lastColor), color[tree]);
    return dp[tree][group][lastColor] = res;
}

int main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> cost[i][j];
    ll res = solve(1, 0, -1);
    if(res >= 1e15) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
