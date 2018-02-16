#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> vs;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
  
bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

bool solve(int x, int y, int xf, int yf, int cnt){
    //printf("%d %d %d %d\n", x, y, xf, yf);
    if(x == xf && y == yf && vs[x][y] == 'X' && cnt >= 1)
        return true;
    vs[x][y] = 'X';
    bool res = false;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && (vs[xx][yy] == '.' || (xx == xf && yy == yf)) )
            res |= solve(xx,yy,xf,yf,cnt+1);
    }
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    x1--;y1--;
    x2--;y2--;
    //printf("%d %d %d %d\n", x1,y1,x2,y2);
    if(solve(x1,y1,x2,y2, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
