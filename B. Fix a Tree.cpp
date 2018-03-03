#include <bits/stdc++.h>
using namespace std;

int v[200005], vis[200005], root;

int solve(int u){
	vis[u] = 1;
	int res = 0;
	if(!vis[v[u]])
		res += solve(v[u]);
	else if(vis[v[u]] == 1 && v[u] != u){
		if(root == -1) root = u;
		v[u] = root;
		res++;
	}
	else if(vis[v[u]] == 1 && v[u] == u && u != root){
		v[u] = root;
		res++;
	}
	vis[u] = 2;
	return res;
}

int main(){

	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	root = -1;
	for(int i = 1; i <= n; i++)
		if(v[i] == i)
			root = i;

	int res = 0;
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			res += solve(i);
	cout << res << endl;
	for(int i = 1; i <= n; i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}


	
