#include <bits/stdc++.h>
using namespace std;

vector<string> vs;
int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	else return true;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		vs.push_back(s);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(vs[i][j] == '.')
				vs[i][j] = 'D';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(vs[i][j] == 'W')
				for(int d = 0; d < 4; d++){
					int x = i + dx[d], y = j + dy[d];
					if(valid(x,y) && vs[x][y] == 'S'){
						cout << "No" << endl;
						return 0;
					}
				}
	cout << "Yes" << endl;
	for(int i = 0; i < n; i++)
		cout << vs[i] << endl;
	return 0;
}
