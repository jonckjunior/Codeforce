#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt += x;
        v.push_back(x);
    }
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++){
            int aux = cnt;
            for(int k = i; k <= j; k++){
                if(v[k] == 0) aux++;
                else aux--;
            }
            res = max(res, aux);
        }
    cout << res << endl;
}
