#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m, b, mod;
int bug[505], dp[505][505];

int main(){
    cin >> n >> m >> b >> mod;
    for(int i = 0; i < n; i++)
        cin >> bug[i];
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k+bug[i] <= b; k++)
                dp[j+1][k+bug[i]] = (dp[j+1][k+bug[i]]%mod + dp[j][k]%mod)%mod;
    int res = 0;
    for(int i = 0; i <= b; i++)
        res = (res%mod + dp[m][i]%mod)%mod;
        
    cout << res << endl;
}
