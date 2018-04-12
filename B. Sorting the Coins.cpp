#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;

int main(){
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> mark(n);
    int h = n - 1;
    int r = 0;
    cout << "1 ";
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        ++r;
        mark[k - 1] = 1;
        while (mark[h] && h >= 0) h--, r--;
        cout << r + 1 << " ";
    }
    cout << endl;
    return 0;
}
