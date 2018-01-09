#include <bits/stdc++.h>

using namespace std;

int v[100005], cnt[100005], dp[100005];

int main() {
    int n,m; cin >> n >> m;
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
        if(cnt[v[i]] == 1) s++;
    }
    dp[0] = s;
    for(int i = 1; i < n; i++){
        cnt[v[i-1]]--;
        if(cnt[v[i-1]] == 0) s--;
        dp[i] = s;
    }
    for(int i = 0; i < m; i++){
        int q; cin >> q;
        q--;
        cout << dp[q] << endl;
    }
    
}
