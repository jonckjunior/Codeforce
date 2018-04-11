#include <bits/stdc++.h>
using namespace std;

struct Dado{
    int e, d, b, c, t, f;
    Dado(int ee, int dd, int bb, int cc, int tt, int ff){
        e = ee; d = dd; b = bb; c = cc; t = tt; f = ff;
    }
    Dado(){
        e = d = b = c = t = f = -1;
    }
};

Dado v[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // memset(v, -1, sizeof v);

    int n; cin >> n;
    int C; cin >> C;
    v[1].c = C;
    v[1].b = 7-v[1].c;
    int E, F; cin >> E >> F;
    v[1].e = E; v[1].d = 7-E;
    v[1].f = F; v[1].t = 7-F;

    for(int i = 2; i <= n; i++){
        cin >> E >> F;
        v[i].e = E; v[i].d = 7-E;
        v[i].f = F; v[i].t = 7-F;
        for(int j = 1; j <= 6; j++)
                if(j != v[i].e && j != v[i].d && j != v[i].f && j != v[i].t && j != v[i-1].b){
                    v[i].c = j;
                    break;
                }
            v[i].b = 7-v[i].c;
    }

    bool flag = false;

    for(int i = 2; i < n; i++)
        if(v[i].b != v[i-1].b && v[i].c != v[i+1].c){
            // printf("dando switch em %d\n", i);
            flag = true;
        }
    if(n >1 && v[n].b != v[n-1].b) flag = true;

    if(!flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
