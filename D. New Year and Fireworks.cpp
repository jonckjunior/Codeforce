#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int vis[305][305], v[35], dp[300][300][30][10], n;

ii h[] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

void solve(int x, int y, int dir, int rec){
    if(dp[x][y][rec][dir])
        return;
    if(rec >= n)
        return;
    vis[x][y] = dp[x][y][rec][dir] = 1;

    int lx=x, ly=y;
    for(int i = 1; i < v[rec]; i++){
        int xx = lx + h[dir].first, yy = ly+h[dir].second;
        lx = xx;
        ly = yy;
        vis[xx][yy] = 1;
    }
    //printf("%d %d terminou em %d %d\n", x, y, lx, ly);
    int d1 = (dir+1)%8;
    int d2 = (dir+8-1)%8;
    solve(lx+h[d1].first, ly+h[d1].second, d1, rec+1);
    solve(lx+h[d2].first, ly+h[d2].second, d2, rec+1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    solve(150,150,0,0);
    int res = 0;
    for(int i = 0; i < 300; i++)
        for(int j = 0; j < 300; j++)
            if(vis[i][j])
                res++;
    cout << res << endl;
    return 0;
}
