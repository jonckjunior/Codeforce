#include <bits/stdc++.h>
using namespace std;

int p, n, m, k;
char mt[505][505];
int vis[505][505];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

void solve(int x, int y){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && !vis[xx][yy] && mt[xx][yy] == '.')
            solve(xx,yy);
    }
    if(p < k){
        mt[x][y] = 'X';
        p++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mt[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j] && mt[i][j] == '.')
                solve(i, j);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << mt[i][j];
        cout << endl;
    }
    
    return 0;
}
