#include <bits/stdc++.h>
using namespace std;

int main() {
    cout.sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;

    string vs[10];
    vs[0] = s;
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < n; j++)
            vs[i] += (vs[i-1][j] == '9' ? '0' : vs[i-1][j] + 1);
    }
    string best = string(n, '9');
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < n; j++){
            rotate(vs[i].rbegin(), vs[i].rbegin()+1, vs[i].rend());
            best = min(best, vs[i]);
        }
    }
    cout << best << endl;
    return 0;
}
