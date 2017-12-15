#include <bits/stdc++.h>

using namespace std;

int v[5];
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v[x]++;
	}
	int res = v[4];
	res += v[3];
	v[1] -= v[3];
	v[1] = max(v[1], 0);
	res += v[2]/2;
	v[2] %= 2;
	if(v[2] == 1){
		res++;
		v[1] -= 2;
	}
	v[1] = max(v[1], 0);
	res += ceil(v[1]/4.0);
	cout << res << endl;
	return 0;
}