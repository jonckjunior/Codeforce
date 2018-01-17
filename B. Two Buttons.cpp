#include <bits/stdc++.h>
using namespace std;

vector<int> dist(20005, -1);

int solve(int n, int m){
    queue<int> q; q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u == m) return dist[u];
        if(u < m && dist[u*2] == -1){
            q.push(u*2);
            dist[u*2] = dist[u] + 1;
        }
        if(u >= 2 && dist[u-1] == -1){
            q.push(u-1);
            dist[u-1] = dist[u] + 1;
        }
    }
    return -1;
}

int main(){
    int n, m; cin >> n >> m;
    cout << solve(n,m) << endl;
    return 0;
}
