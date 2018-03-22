#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    k--;
    bool flag = true;
    for(int i = k; i < n; i++)
        if(v[k] != v[i])
            flag = false;
    if(flag){
        int aux = 0;
        for(int i = k; i >= 0; i--)
            if(v[k] != v[i]){
                aux = i+1;
                break;
            }
        cout << aux << endl;
    }
    else cout << -1 << endl;
    return 0;
}
