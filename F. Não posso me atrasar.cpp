#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dist[105][105];
map<string, int> mapa;

int main(){
	int x, m, n;
	while(cin >> x >> m >> n, x+m+n != 0){
		mapa.clear();
		int k = 1;
		for(int i = 0; i <= n+5; i++)
			for(int j = 0; j <= n+5; j++)
				dist[i][j] = 1e9;
		for(int i = 0; i < m; i++){
			string a, b; cin >> a >> b;
			int w; cin >> w;
			int u = mapa[a], v = mapa[b];
			if(mapa[a] == 0) mapa[a] = u = k++;
			if(mapa[b] == 0) mapa[b] = v = k++;
			dist[u][v] = w;
		}

		for(int l = 1; l <= n; l++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
		int s = mapa["varzea"], t = mapa["alto"];
		int res = dist[s][t];
		if(x <= 30) res += 30;
		else res += 50;
		printf("%02d:%02d\n", 17 + (res/60), res%60);
		if(res > 60)
			puts("Ira se atrasar");
		else
			puts("Nao ira se atrasar");
	}
	return 0;
}
