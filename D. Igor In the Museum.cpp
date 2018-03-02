#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<string> vs;
map<int,int> comp_to_len;
int n, m, q, tam, comp, vis[1005][1005], cord_to_comp[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	else return true;
}

void dfs(int x, int y, int comp){
	// printf("here %d %d\n", x, y);
	cord_to_comp[x][y] = comp;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i], yy = y + dy[i];
		if(valid(xx,yy) && vs[xx][yy] == '.' && !vis[xx][yy])
			dfs(xx,yy, comp);
		else if(valid(xx,yy) && vs[xx][yy] == '*')
			tam++;
	}
}

int main(){
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		vs.push_back(s);
	}
	comp = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(vs[i][j] == '.' && !vis[i][j]){
				tam = 0;
				dfs(i, j, comp);
				comp_to_len[comp] = tam;
				comp++;
			}

	for(int i = 0; i < q; i++){
		int x, y; cin >> x >> y;
		x--;y--;
		int c = cord_to_comp[x][y];
		cout << comp_to_len[c] << endl;
	}

	return 0;
}


