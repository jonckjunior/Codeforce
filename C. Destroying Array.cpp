#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long int ll;


ll v[100005], p[100005], sum[100005], alive[100005];

int pai(int u){return p[u] = (p[u] == u ? u : pai(p[u]));}

ll unionFind(int x, int y){
    if(!alive[x] || !alive[y]) return 0;
    x = pai(x), y = pai(y);
    p[y] = x;
    sum[x] += sum[y];
    return sum[x];
}

int main() {
    cout.sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        cin >> v[i];
        sum[i] = v[i];
    }
    vector<int> process;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        process.push_back(x);
    }
    reverse(process.begin(), process.end());
    ll maxi = 0;
    vector<ll> res;
    for(int pos : process){
        res.push_back(maxi);
        alive[pos] = 1;
        ll val = sum[pos];
        val = max(val, unionFind(pos, pos+1));
        val = max(val, unionFind(pos-1, pos));
        maxi = max(maxi, val);
    }
    reverse(res.begin(), res.end());
    for(ll val : res)
        cout << val << endl;
    return 0;
}
