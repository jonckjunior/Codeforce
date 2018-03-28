#include <bits/stdc++.h>
using namespace std;

int cnt[1005];

int main(){
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        v.push_back(x);
        cnt[x] = 1;
    }
    for(int val : v){
        cout << val << " ";
        int aux = 1;
        for(int i = 1; i <= n*k && aux < n; i++)
            if(cnt[i] == 0){
                cnt[i] = 1;
                aux++;
                cout << i << " ";
            }
        cout << endl;
    }
    return 0;
}
