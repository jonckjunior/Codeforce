#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;

double solve(int u, int len, int pai){
    if((int)adj[u].size() == 1 && adj[u][0] == pai)
        return len;
    else{
        double viz = 0, res = 0;
        for(int v : adj[u])
            if(v != pai){
                res += solve(v, len+1, u);
                viz++;
            }
        return (res/viz);
    }
}

int main(){
    int n; cin >> n;
    adj.assign(n+5, vi());
    
    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n == 1) puts("0");
    else printf("%.6f\n", solve(0,0,-1));
    return 0;
}
