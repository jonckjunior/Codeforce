#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000;
int v[maxn], tree[4*maxn];

int left(int p){return (p << 1);}
int right(int p){return (p << 1) + 1;}

void update(int u, int L, int R, int idx, int val, int turn){
	if(L > idx || R < idx)
		return;
	if(L == R && L == idx){
		tree[u] = val;
	}
	else{
		int mid = (L+R)/2;
		update(left(u), L, mid,    idx, val, turn-1);
		update(right(u), mid+1, R, idx, val, turn-1);
		if(turn%2 == 0)
			tree[u] = tree[left(u)] ^ tree[right(u)];
		else
			tree[u] = tree[left(u)] | tree[right(u)];
		// printf("tree[%d] = %d, com altura = %d\n", u, tree[u], turn);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	n = (1 << n);
	int altura = log2(n);
	// printf("altura = %d\n", altura);
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		update(1, 1, n, i, x, altura);
	}
	for(int i = 0; i < m; i++){
		int idx, val; cin >> idx >> val;
		// printf("%d %d\n", idx, val);
		update(1, 1, n, idx, val, altura);
		cout << tree[1] << endl;
	}
	return 0;
}
