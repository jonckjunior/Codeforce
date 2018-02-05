#include <bits/stdc++.h>
using namespace std;

char mt[55][55];
int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int vis[55][55];
bool found;

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

void solve(int x, int y, char color, int d){
    vis[x][y] = d;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && mt[xx][yy] == mt[x][y]){
            if(!vis[xx][yy])
                solve(xx,yy,mt[xx][yy],d+1);
            else if(vis[xx][yy]-d+1 >= 4)
                found = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mt[i][j];
    found = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j])
                solve(i,j,mt[i][j],1);

    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
