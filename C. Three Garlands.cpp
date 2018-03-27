#include <bits/stdc++.h>

using namespace std;

int v[10000005];

int main() {
    int k1, k2, k3; cin >> k1 >> k2 >> k3;
    int t = 0;
    bool flag2 = false;
    for(int i = 0; i <= 10; ++i)
        for(int j = 0; j <= 10; ++j)
            for(int k = 0; k <= 10; ++k) {
                ++t;
                int x = i, y = j, z = k;
                for (int a = 0; a < 1000; ++a) {
                    v[x] = t;
                    v[y] = t;
                    v[z] = t;
                    x += k1, y += k2, z += k3;
                }
                bool flag = true;
                for (int a = 0; a < 1000; ++a)
                    if (v[a] != t) {
                        flag = false;
                        break;
                    }
                if (flag) flag2 = true;
            }
    if (flag2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
