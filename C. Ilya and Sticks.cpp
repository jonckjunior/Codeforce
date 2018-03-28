#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int cnt[1000005];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    deque<ll> v;
    for(int i = 1000000; i >= 1; i--){
        while(cnt[i] >= 2){
            v.push_back(i);
            cnt[i] -= 2;
        }
        while(cnt[i] >= 1 && cnt[i-1] >= 1){
            v.push_back(i-1);
            cnt[i]--;cnt[i-1]--;
        }
    }
    ll res = 0;
    while(v.size() >= 2){
        ll a = v.front(); v.pop_front();
        ll b = v.front(); v.pop_front();
        // cout << a << " " << b << endl;
        res += a*b;
    }
    cout << res << endl;
    return 0;
}
