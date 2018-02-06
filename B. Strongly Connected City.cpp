#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

/*
    3 3
    ><>
    v^v
    
*/

vector<ii> mt[30][30];
int n, m, vis[30][30], nodo;

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

void solve(int x, int y){
    vis[x][y] = 1;
    nodo++;
    for(int i = 0; i < (int)mt[x][y].size(); i++){
        int xx = mt[x][y][i].first, yy = mt[x][y][i].second;
        if(!vis[xx][yy])
            solve(xx,yy);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(s1[i] == '<' && valid(i,j-1))
                mt[i][j].push_back(ii(i,j-1));
            if(s1[i] == '>' && valid(i,j+1))
                mt[i][j].push_back(ii(i,j+1));
            if(s2[j] == 'v' && valid(i+1,j))
                mt[i][j].push_back(ii(i+1,j));
            if(s2[j] == '^' && valid(i-1,j))
                mt[i][j].push_back(ii(i-1,j));
        }
    bool found = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
                nodo = 0;
                memset(vis, 0, sizeof vis);
                solve(i,j);
                if(nodo != n*m) found = false;
        }
    if(found) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
