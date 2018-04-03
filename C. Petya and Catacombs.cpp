#include <bits/stdc++.h>
using namespace std;

int main(){


    int n; cin >> n;
    vector<int> v, u(n + 1);
    int k = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);

    }
    u[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (u[v[i - 1]] == 1) u[i] = 1, u[v[i - 1]] = 0;
        else ++k, u[i] = 1;
    }
    //0 1 0 1 3
    cout << k << endl;

    return 0;
}
