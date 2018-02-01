#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int bt[100005], dp[100005];

vector<int> p, v;

vector<int> getPrime(int n){
    int root = sqrt(n);
    vector<int> res;
    for(int i = 0; i < (int)p.size() && p[i] <= root; i++){
        if(n%p[i] == 0){
            n/=p[i];
            res.push_back(p[i]);
        }
        while(n%p[i] == 0) n /= p[i];
    }
    if(n != 1) res.push_back(n);
    return res;
}

int main(){
    //ios::sync_with_stdio(false);
    for(int i = 0; i <= 100000; i++)
        bt[i] = 1;
    bt[0] = bt[1] = 0;
    for(ll i = 2; i <= 100000; i++) if(bt[i]){
        p.push_back(i);
        for(ll j = i*i; j <= 100000; j += i)
            bt[j] = 0;
    }
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    int res = 0;
    for(int x : v){
        vector<int> divisores = getPrime(x);
        for(int divi : divisores)
            dp[x] = max(dp[x], dp[divi]+1);
        for(int divi : divisores)
            dp[divi] = max(dp[divi], dp[x]);
        res = max(res, dp[x]);
    }
    cout << res << endl;
    return 0;
}
