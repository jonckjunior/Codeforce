#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int esq = v.front(), dir = v.back();
    int idx_esq = 0, idx_dir = n-1;
    int adam = 0, weiss = 0;
    while(idx_esq <= idx_dir){
        if (esq <= dir)
            esq += v[++idx_esq], ++adam;
        else
            dir += v[--idx_dir], ++weiss;
    }
    cout << adam << " " << weiss << endl;
    return 0;
}
