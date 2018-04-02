#include <bits/stdc++.h>
using namespace std;

int v[105];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[x]++;
    }
    int res = 0;
    for(int i = 1; i <= 100; i++)
        res += v[i]/2;
    cout << res/2 << endl;
    return 0;
}
