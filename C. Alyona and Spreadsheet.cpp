#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> mt, dp;
vi maxi;
/*
    5 4
    1 2 3 5
    3 1 3 2
    4 5 2 3
    5 5 3 2
    4 4 3 4
    6
    1 1
    2 5
    4 5
    3 5
    1 3
    1 5
*/

int main(){
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    mt.assign(n+5, vi(m+5, 0));
    dp.assign(n+5, vi(m+5, 0));
    maxi.assign(n+5, 0);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mt[i][j];
        
    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++){
            if(mt[i-1][j] <= mt[i][j])
                dp[i][j] = dp[i-1][j] + 1 ;
            else
                dp[i][j] = 1;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            maxi[i] = max(maxi[i], dp[i][j]);
    
    int q; cin >> q;
    
    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        if(maxi[r] >= r-l+1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
        
}
