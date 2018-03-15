#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj, comp;
vi vis;

void solve(int u, vi& vec){
	if(adj[u].size() == 0)
		return;
	vis[u] = 1;
	vec.push_back(u);
	for(int v : adj[u])
		if(!vis[v])
			solve(v, vec);
}

int main(){
	int n, m; cin >> n >> m;
	adj.assign(n+5, vi());
	vis.assign(n+5, 0);

	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool flag = true;

	for(int i = 1; i <= n; i++)
		if(!vis[i]){
			vi vec;
			solve(i, vec);
			if(vec.size() > 0)
				comp.push_back(vec);
			if(vec.size() > 3)
				flag = false;
		}

	if(flag){
		int k = 1;
		for(int i = 0; i < (int)comp.size(); i++){
			while(comp[i].size() < 3){
				while(vis[k]) k++;
				if(k > n) break;
				vis[k] = 1;
				comp[i].push_back(k++);
			}
			if(comp[i].size() != 3)
				flag = false;
		}
		if(flag){
			for(int i = 0; i < (int)comp.size(); i++){
				for(int v : comp[i])
					printf("%d ", v);
				printf("\n");
			}
			k = 1;
			for(int i = 1; i <= n; i++){
				if(!vis[i]){
					printf("%d ", i);
					k++;
				}
				if(k%4 == 0)
					printf("\n");
			}
		}
		else
			cout << -1 << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}
