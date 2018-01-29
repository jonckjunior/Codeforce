#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll v[1000005], n, m;
int dp[1005][1005][5];

bool solve(int pos, int sum, int el){
    if(pos == n)
        return (sum == 0 && el > 0);
    if(dp[pos][sum][el] != -1) return dp[pos][sum][el];
    return dp[pos][sum][el] = (solve(pos+1, sum, el) || solve(pos+1, (sum + v[pos])%m, 1));
}

int main(){
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    if(n >= m || solve(0,0,0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
