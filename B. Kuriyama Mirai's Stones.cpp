#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[100005], dp2[100005];

int main() {
    int n; cin >> n;
    vector<int> v, v2;
    v.push_back(0);
    v2.push_back(0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        v2.push_back(x);
    }
    sort(v2.begin(), v2.end());
    
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + v[i];
        dp2[i] = dp2[i-1] + v2[i];
    }
    
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int t,l,r; cin >> t >> l >> r;
        if(t == 1)
            cout << dp[r]-dp[l-1] << endl;
        else
            cout << dp2[r]-dp2[l-1] << endl;
    }
}
