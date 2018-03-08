#include <bits/stdc++.h>
using namespace std;

int v[1000005], prefix[1000005], suffix[1000005], tree[4000005];
map<int,int> cont;

int left(int p){return (p << 1);}
int right(int p){return (p << 1) + 1;}

void update(int u, int esq, int dir, int val){
	if(esq > val || dir < val) return;
	if(esq == dir && dir == val)
		tree[u]++;
	else{
		int mid = (esq+dir)/2;
		update(left(u), esq, mid, val);
		update(right(u), mid+1, dir, val);
		tree[u] = tree[left(u)] + tree[right(u)];
	}
}

int query(int u, int esq, int dir, int L, int R){
	if(dir < L || esq > R) return 0;
	if(esq >= L && dir <= R) return tree[u];
	else{
		int mid = (esq+dir)/2;
		return query(left(u), esq, mid, L, R) + query(right(u), mid+1, dir, L, R);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];

	for(int i = 0; i < n; i++){
		int x = v[i];
		cont[x]++;
		prefix[i] = cont[x];
	}
	cont.clear();
	for(int i = n-1; i >= 0; i--){
		int x = v[i];
		cont[x]++;
		suffix[i] = cont[x];
	}
	long long int res = 0;
	for(int i = n-1; i > 0; i--){
		update(1, 1, n, suffix[i]);
		res += query(1, 1, n, 1, prefix[i-1] - 1);
	}
	cout << res << endl;
	return 0;
}
