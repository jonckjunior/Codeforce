#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    
    int n, d; cin >> n >> d;
    
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int res = 0;
    for(int i = 1; i < n; i++){
        if(v[i] > v[i-1]) continue;
        int x = (v[i-1]-v[i])/d + 1;
        //printf("dif = %d - %d\n", v[i], v[i-1]);
        //printf("Aumentando %d em pos %d\n", x, i);
        v[i] += x*d;
        res += x;
    }
    cout << res << endl;
    return 0;
}
