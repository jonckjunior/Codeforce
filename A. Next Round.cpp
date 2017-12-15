#include <bits/stdc++.h>

using namespace std;

int v[105];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	//sort(v+n, v);
	int pos = 0, score = v[m-1], res = 0;
	while(pos < n && v[pos] > 0 && v[pos] >= score) pos++, res++;
	cout << res << endl;
}