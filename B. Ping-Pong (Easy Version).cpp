#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<vi> adj;
vi vis;
vector<ii> pares;

bool solve(int u, int t){
	vis[u] = 1;
	if(u == t) return true;
	bool res = false;
	for(int v : adj[u])
		if(!vis[v])
			res |= solve(v, t);
	return res;
}

int main(){
	int n; cin >> n;
	adj.assign(n+5, vi());
	
	for(int i = 0; i < n; i++){
		int op, x, y; cin >> op >> x >> y;
		if(op == 1){
			int nodo = pares.size();

			for(int i = 0; i < (int)pares.size(); i++){
				int a = pares[i].first, b = pares[i].second;
				int c = x, d = y;
				if(c < a && a < d || c < b && b < d)
					adj[i].push_back(nodo);
			}

			for(int i = 0; i < (int)pares.size(); i++){
				int a = x, b = y;
				int c = pares[i].first, d = pares[i].second;
				if(c < a && a < d || c < b && b < d)
					adj[nodo].push_back(i);
			}

			pares.push_back(ii(x,y));
		}
		else{
			vis.assign(n+5, 0);
			if(solve(x-1,y-1)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
	return 0;
}
