#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int mt[305][305], n, m, k, cnt;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

vector<vii> adj;

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

void solve(int x, int y, int z){
    mt[x][y] = z;
    adj[z].push_back(ii(x+1,y+1));
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && !mt[xx][yy])
            solve(xx,yy,z);
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n >> m >> k;
    adj.assign(k+5, vii());
    cnt = 1;
    for(int i = 0; i < n && cnt < k; i++)
        for(int j = 0; j < m-1 && cnt < k; j++)
            if(mt[i][j] == 0 && mt[i][j+1] == 0)
                mt[i][j] = mt[i][j+1] = cnt++;
    for(int i = 0; i < n-1 && cnt < k; i++)
        for(int j = 0; j < m && cnt < k; j++)
            if(mt[i][j] == 0 && mt[i+1][j] == 0)
                mt[i][j] = mt[i+1][j] = cnt++;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mt[i][j] == 0)
                solve(i,j,k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mt[i][j] != k)
                adj[mt[i][j]].push_back(ii(i+1,j+1));
                
    for(int i = 1; i <= k; i++){
        cout << (int)adj[i].size() << " ";
        for(int j = 0; j < (int)adj[i].size(); j++)
            cout << adj[i][j].first << " " << adj[i][j].second << " ";
        cout << endl;
    }
    

    
    return 0;
}
