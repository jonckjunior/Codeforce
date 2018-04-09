#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;

    map<int,int> mapa;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mapa[x] = i;
    }

    int pos = mapa[1];
    long long int res = 0;
    for(int i = 1; i <= n; i++){
        res += abs(pos-mapa[i]);
        pos = mapa[i];
    }
    cout << res << endl;
    return 0;
}
