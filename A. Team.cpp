#include <bits/stdc++.h>

using namespace std;

int v[1005][5];

int main(){
	int n; cin >> n;
	int res = 0;
	for(int i = 0; i < n; i++){
		int aux = 0;
		for(int j = 0; j < 3; j++){
			int x; cin >> x;
			aux += x;
		}
		if(aux >= 2) res++;
	}
	cout << res << endl;
	return 0;
}