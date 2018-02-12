#include <bits/stdc++.h>
using namespace std;

struct State{
    int x, y, v;
    State(int xx, int yy, int vv){
        x = xx; y = yy; v = vv;
    }
    bool operator < (const State& other) const{
        return v < other.v;
    }
};

int n, m, k;
vector<State> vec;
vector<string> vs;
int vis[55][55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

int solve(int x, int y){
    vis[x][y] = 1;
    int res = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && !vis[xx][yy] && vs[xx][yy] == '.')
            res += solve(xx,yy);
    }
    return res;
}

void fillSolve(int x, int y){
    vs[x][y] = '*';
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && vs[xx][yy] == '.')
            fillSolve(xx,yy);
    }
}

int main(){
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    
    for(int i = 0; i < n; i++){
        if(!vis[i][0] && vs[i][0] == '.')
            solve(i,0);
        if(!vis[i][m-1] && vs[i][m-1] == '.')
            solve(i, m-1);
    }
    
    for(int i = 0; i < m; i++){
        if(!vis[0][i] && vs[0][i] == '.')
            solve(0,i);
        if(!vis[n-1][i] && vs[n-1][i] == '.')
            solve(n-1, i);
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j] && vs[i][j] == '.'){
                int res = solve(i, j);
                vec.push_back(State(i,j,res));
            }
    sort(vec.begin(), vec.end());
    
    int pos = 0, res = 0, len = vec.size();
    while(pos < len && len-pos > k){
        //printf("%d %d %d\n", vec[pos].v, vec[pos].x, vec[pos].y);
        res += vec[pos].v;
        fillSolve(vec[pos].x, vec[pos].y);
        pos++;
    }
    cout << res << endl;
    for(int i = 0; i < n; i++)
        cout << vs[i] << endl;
    return 0;
}
