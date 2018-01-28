#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll w[200005], h[200005];
ll sum;

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    multiset<ll> ms;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> h[i];
        sum += w[i];
        ms.insert(h[i]);
        // cout << "inserindo " << h[i] << endl;
    }
    // cout << ms.size() << endl;
    for(int i = 0; i < n; i++){
        auto it = ms.find(h[i]);
        if(it != ms.end())
            ms.erase(it);
        sum -= w[i];
        // cout << sum << endl;
        // cout << ms.size() << endl;
        // cout << *ms.rbegin() << endl;
        cout << 1LL * sum * (*ms.rbegin()) << " ";
        ms.insert(h[i]);
        sum += w[i];
    }
    cout << endl;
    return 0;
}
