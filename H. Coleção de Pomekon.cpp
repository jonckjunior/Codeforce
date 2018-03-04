#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n, n != 0){
		map<string, int> mapa;
		for(int i = 0; i < n; i++){
			string s; cin >> s;
			mapa[s] = 1;
		}
		printf("Falta(m) %d pomekon(s).\n", 151 - (int)mapa.size());
	}
	return 0;
}
