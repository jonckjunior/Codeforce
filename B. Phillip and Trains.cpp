#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/* Canto do Felipera

*/

struct Trem{
    int x, y1,y2;
    Trem(int _x, int _y1, int _y2){x = _x; y1 = _y1; y2 = _y2;}
};

vector<string> vs;
vector<Trem> vt;

int vis[5][105][105], n, k;

bool validTrain(int x, int y, int turn) {
    for (Trem tr : vt)
        if (x == tr.x && y >= tr.y1-2*turn && y <= tr.y2-2*turn)
            return false;
    return true;
}

bool valid(int x, int y){
    if(x < 0 || x >= 3 || y < 0 || y >= n) return false;
    else return true;
}

bool solve(int x, int y, int turn){
    if (y == n - 1) return true;
    vis[x][y][turn] = 1;
    bool res = false;
    for(int i = -1; i <= 1; i++){
        bool aux = true; 
        int xx = x+i, yy = y+1;
        if(valid(xx,yy) && !vis[xx][yy][turn + 1] && validTrain(x,yy, turn) && validTrain(xx,yy, turn) && validTrain(xx,yy,turn+1))
            res |= solve(xx, yy, turn+1);
    }   
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for(int caso = 0; caso < t; caso++){
        memset(vis, 0, sizeof vis);
        vs.clear();
        vt.clear();
        cin >> n >> k;
        
        for(int i = 0; i < 3; i++){
            string s; cin >> s;
            vs.push_back(s);
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                if (isalpha(vs[i][j]) && vs[i][j] != 's') {
                    char c = vs[i][j];
                    int a = j;
                    while (j < n && vs[i][j] == c) ++j;
                    vt.push_back(Trem(i, a, j - 1));
                    --j;
                }
            }
        }
        
        bool res = false;
        for(int i = 0; i < 3; i++)
            if(vs[i][0] == 's')
                res |= solve(i,0,0);
        if(res) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}
