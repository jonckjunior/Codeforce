#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> vs;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int vis[15][15][5], limpa[15][15];

int MOD(int base, int m){return(base%m);}

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	else return true;
}

int solve(int x, int y, int pos){
	if(vis[x][y][pos])
		return 0;
	int res = !limpa[x][y];
	vis[x][y][pos] = 1;
	limpa[x][y] = 1;
	int xx = x + dx[pos], yy = y + dy[pos];
	if(valid(xx,yy) && vs[xx][yy] == '.')
		res += solve(xx,yy,pos);
	else
		res += solve(x,y,MOD(pos+1,4));
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		vs.push_back(s);
	}
	map<char,int> mapa;
	mapa['U'] = 0;
	mapa['R'] = 1;
	mapa['D'] = 2;
	mapa['L'] = 3;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(vs[i][j] != '.' && vs[i][j] != '*'){
				char lastPos = vs[i][j];
				vs[i][j] = '.';
				cout << solve(i, j, mapa[lastPos]) << endl;
			}
    return 0;
}
