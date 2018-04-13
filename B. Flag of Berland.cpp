#include <bits/stdc++.h>
using namespace std;
//sim

int n, m;
vector<string> vs;

int h[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int mark[1234][1234];
int dp_x[5], dp_y[5];

int x_min, x_max, y_min, y_max;
int cnt;

int dfs(int i, int j, char c) {
  ++cnt; mark[i][j] = 1;
  x_min = min(i, x_min); x_max = max(i, x_max);
  y_min = min(j, y_min); y_max = max(j, y_max);
  for (int a = 0; a < 4; ++a) {
    int x = i + h[a][0];
    int y = j + h[a][1];
    if (x >= 0 && x < n && y >= 0 && y < m && !mark[x][y] && vs[x][y] == c)
      dfs(x, y, c);
  }
}

int solve(char letra, int daVez){
    cnt = 0;
    x_min = y_min = 1000;
    x_max = y_max = -1000;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            if(vs[i][j] == letra && !mark[i][j])
                dfs(i, j, letra);
    dp_x[daVez] = x_max-x_min;
    dp_y[daVez] = y_max-y_min;
    if (cnt == (x_max - x_min + 1) * (y_max - y_min + 1)) return cnt;
    return -1;
}

int main(){
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    
    int cnt_R=solve('R', 0), cnt_G=solve('G', 1), cnt_B=solve('B', 2);
    
    if(cnt_R == cnt_G && cnt_G == cnt_B && cnt_R+cnt_G+cnt_B == n*m
       && dp_x[0] == dp_x[1] && dp_x[1] == dp_x[2] &&
       dp_y[0] == dp_y[1] && dp_y[1] == dp_y[2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
