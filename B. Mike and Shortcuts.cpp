#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;

int main(){
	int n; cin >> n;
	adj.assign(n+5, vi());
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		adj[i].push_back(x);
		if(i+1 <= n){
			adj[i].push_back(i+1);
			adj[i+1].push_back(i);
		}
	}

	vi dist(n+5, 1e9);
	queue<int> q; q.push(1);
	dist[1] = 0;

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : adj[u])
			if(dist[u]+1 < dist[v]){
				dist[v] = dist[u]+1;
				q.push(v);
			}
	}

	for(int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}


