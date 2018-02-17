#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;

int pai[5005], n, dp[5005];

int dfs(int u, int sum){
    if(u >= (1 << n)) return dp[u] = pai[u]+sum;
    return dp[u] = max(dfs(u*2, sum+pai[u]), dfs(u*2+1,sum+pai[u]));
}

int solve(int u, int sum, int maxi){
    if(u >= (1 << n)) return maxi-(dp[u]+sum);
    int post = maxi-(dp[u]+sum);
    int esq = solve(u*2, sum+post, maxi);
    int dir = solve(u*2+1, sum+post, maxi);
    return esq+dir+post;
}

int main(){
    
    cin >> n;
    pai[1] = 0;
    for(int i = 2; i <= (1 << (n+1)) - 1; i++)
        cin >> pai[i];
    int maxi = dfs(1, 0);
    cout << solve(1, 0, maxi) << endl;
    return 0;
}
