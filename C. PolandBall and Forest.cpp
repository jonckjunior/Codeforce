#include <bits/stdc++.h>
using namespace std;

int p[10005];

int pai(int u){
    while(p[u] != u){
        p[u] = p[p[u]];
        u = p[u];
    }
    return u;
}

void union_set(int x, int y){
    x = pai(x), y = pai(y);
    p[x] = y;
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        p[i] = i;
        
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        union_set(i,x);
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(p[i] == i)
            res++;
    cout << res << endl;
    return 0;
}
