#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, m, w;
int peso[1005], beleza[1005];
int sumPeso[1005], sumBeleza[1005], dp[1005][1005];
vector<vi> adj, comp;
vi vis;

void init(int u, vi& vec, int numComp){
	vis[u] = 1;
	sumPeso[numComp] += peso[u];
	sumBeleza[numComp] += beleza[u];
	vec.push_back(u);
	for(int v : adj[u])
		if(!vis[v])
			init(v, vec, numComp);
}

int solve(int u, int k){
	if(k > w)
		return -1e9;
	if(u >= (int)comp.size())
		return 0;
	if(dp[u][k] != -1)
		return dp[u][k];
	int res = solve(u+1, sumPeso[u] + k) + sumBeleza[u];
	res = max(res, solve(u+1, k));
	for(int v : comp[u])
		res = max(res, solve(u+1, peso[v] + k) + beleza[v]);
	return dp[u][k] = res;
}

int main(){
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> w;
	adj.assign(n+5, vi());
	vis.assign(n+5, 0);

	for(int i = 0; i < n; i++)
		cin >> peso[i];
	for(int i = 0; i < n; i++)
		cin >> beleza[i];
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int numComp = 0;
	for(int i = 0; i < n; i++)
		if(!vis[i]){
			vi vec;
			init(i, vec, numComp++);
			comp.push_back(vec);
		}

	/*for(int i = 0; i < numComp; i++){
		printf("Componente %d: ", i+1);
		for(int val : comp[i])
			printf("%d ", val);
		puts("");
		printf("w=%d b=%d\n", sumPeso[i], sumBeleza[i]);
	}
*/
	cout << solve(0, 0) << endl;

	return 0;
}
