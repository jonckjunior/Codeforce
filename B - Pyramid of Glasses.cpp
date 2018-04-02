#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, t;
double dp[30][30];

void solve(int x, int y, double t, int k){
    if(k == n || t == 0) return;
    if(dp[x][y] == 1){
        solve(x+1, y-1, t/2.0, k+1);
        solve(x+1, y+1, t/2.0, k+1);
    }
    else{
        dp[x][y] += t;
        if(dp[x][y] > 1){
            double dif = dp[x][y]-1.0;
            solve(x+1, y-1, dif/2.0, k+1);
            solve(x+1, y+1, dif/2.0, k+1);
        }
    }
    //printf("%d %d = %.2f\n", x, y, dp[x][y]);
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n >> t;
    for(int i = 0; i < t; i++)
        solve(0,15,1,0);
    int res = 0;
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            if(dp[i][j] == 1)
                res++;
    cout << res << endl;
    return 0;
}
