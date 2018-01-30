#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    if(count(v.begin(), v.end(), 1) > 0)
        cout << n - count(v.begin(), v.end(), 1) << endl;
    else{
        int res = 1e9;
        for(int i = 0; i < n; i++){
            int g = v[i];
            for(int j = i+1; j < n; j++){
                g = __gcd(g, v[j]);
                if(g == 1){
                    res = min(res, j-i + n - 1);
                }
            }
        }
        if(res >= 1e9) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
