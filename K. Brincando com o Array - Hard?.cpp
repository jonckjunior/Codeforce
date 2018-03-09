#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int tree[4*maxn];

int left(int p){return (p << 1);}
int right(int p){return (p << 1) + 1;}

void update(int u, int L, int R, int val){
	if(L > val || R < val)
		return;
	else if(L == R && L == val)
		tree[u]++;
	else{
		int mid = (L+R)/2;
		update(left(u), L, mid, val);
		update(right(u), mid+1, R, val);
		tree[u] = tree[left(u)] + tree[right(u)];
	}
}

int query(int u, int L, int R, int K){
	if(L == R)
		return L;
	else{
		int mid = (L+R)/2;
		if(tree[right(u)] >= K)
			return query(right(u), mid+1, R, K);
		else
			return query(left(u), L, mid, K-tree[right(u)]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, q;
	while(cin >> n >> q, n+q != 0){
		memset(tree, 0, sizeof tree);
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			update(1, 1, maxn, x);
		}
		for(int i = 0; i < q; i++){
			int op, val; cin >> op >> val;
			// printf("%d %d\n", op, val);
			if(op == 1) update(1, 1, maxn, val);
			else cout << query(1, 1, maxn, val) << endl;
		}
	}
	return 0;
}
