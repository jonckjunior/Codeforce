#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int res = 0;
    for(int i = 0; i < n-1; i++){
        int x = v[i] + v[i+1];
        if(x < k){
            v[i+1] += (k-x);
            res += (k-x);
        }
    }
    cout << res << endl;
    for(int i = 0; i < n; i++){
        if(i+1 == n) printf("%d\n", v[i]);
        else         printf("%d ", v[i]);
    }
}
