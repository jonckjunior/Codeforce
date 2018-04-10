#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t, s, q; cin >> t >> s >> q;
    int res = 0;
    while(s < t)
        s *= q, res++;
    cout << res << endl;
    return 0;
}
