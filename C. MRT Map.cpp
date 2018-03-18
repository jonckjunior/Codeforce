#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
vector<vii> adj;

int func_cost(string& s1, string& s2){
	int v[30] = {0}, v2[30] = {0};
	int res = 0;
	for(char c : s1)
		v[c-'a'] = 1;
	for(char c : s2)
		v2[c-'a'] = 1;
	for(int i = 0; i < 26; i++)
		if(v[i] + v2[i] == 2){
			res++;
		}
	return res;
}

int solve(int ss, int tt){
	queue<int> q; q.push(ss);
	vi in_queue(n+5, 0);
	vi dist(n+5, 1e9);
	dist[ss] = 0;
	in_queue[ss] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		in_queue[u] = 0;
		for(ii viz : adj[u]){
			int v = viz.first, w = viz.second;
			if(dist[u]+w < dist[v]){
				dist[v] = dist[u]+w;
				if(!in_queue[v]){
					q.push(v);
					in_queue[v] = 1;
				}
			}
		}
	}
	return dist[tt];
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	adj.assign(n+5, vii());
	vector<string> vs;

	vs.push_back("Jonckera");
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < (int)s.size(); j++)
			s[j] = tolower(s[j]);
		vs.push_back(s);
	}
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		int w = func_cost(vs[u], vs[v]);
		adj[u].push_back(ii(v,w));
		adj[v].push_back(ii(u,w));
	}
	int s, t; cin >> s >> t;
	cout << solve(s,t) << endl;
    return 0;
}
