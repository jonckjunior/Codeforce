#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll md = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    vector<string> vs;

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }

    ll res = 1;
    for(int i = 0; i < m; i++){
        set<char> s;
        for(int j = 0; j < n; j++)
            s.insert(vs[j][i]);
        res = (res%md * s.size()%md)%md;
    }
    cout << res << endl;
    return 0;
}
