#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);    
    int n; cin >> n;
    map<int,int> mapa;
    int best = -1, freq = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mapa[x]++;
        if(mapa[x] > freq){
            freq = mapa[x];
            best = x;
        }
    }
    cout << best << endl;
    return 0;
}
