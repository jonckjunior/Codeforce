#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x, y, x1, y1; cin >> t >> x >> y >> x1 >> y1;
    string s; cin >> s;
    int xd = x1 - x, yd = y1 - y;
    int k = 0;
    bool flag = false;
    ///cout << xd << " " << yd << endl;
    for (char c : s) {
        ++k;
        if (xd < 0 && c == 'W') ++xd;
        if (yd < 0 && c == 'S') ++yd;
        if (xd > 0 && c == 'E') --xd;
        if (yd > 0 && c == 'N') --yd;
        if (xd == 0 && yd == 0) { flag = true; break; }

    }
    if (flag)
        cout << k << endl;
    else
        cout << -1 << endl;
    return 0;
}
