#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n1,n2,k1,k2,mod=100000000;
int dp[105][105][5];

/*
    2 1 1 10
    AAB
*/

int solve(int v1, int v2, int last){
    if(v1 < 0 || v2 < 0) return 0;
    if(dp[v1][v2][last] != -1) return dp[v1][v2][last];
    if(v1 == 0 && v2 == 0) return 1;
    int res = 0;
    if(last == 0){
        for(int i = 1; i <= k2; i++)
            res = (res%mod + solve(v1, v2-i, 1)%mod)%mod;
    }
    else{
        for(int i = 1; i <= k1; i++)
            res = (res%mod + solve(v1-i, v2, 0)%mod)%mod;
    }
    return dp[v1][v2][last] = res%mod;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n1 >> n2 >> k1 >> k2;
    int r1 = solve(n1,n2,0)%mod;
    int r2 = solve(n1,n2,1)%mod;
    cout << (r1+r2)%mod << endl;
    return 0;
}
