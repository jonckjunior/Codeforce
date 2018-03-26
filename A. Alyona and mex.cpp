#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int len = 1e9;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        len = min(len, y-x+1);
    }
    cout << len << endl;
    int k = 0;
    for(int i = 0; i < n; i++){
        cout << k++ << " ";
        k %= len;
    }
    cout << endl;
    return 0;
}
