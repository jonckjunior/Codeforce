#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c; cin >> a >> b >> c;
	int maxi = 0;
	for(int i = 0; i < 2; i++){
		int res = (i == 0 ? a+b : a*b);
		for(int j = 0; j < 2; j++){
			int aux = (j == 0 ? res + c : res*c);
			maxi = max(maxi, aux);
		}
	}
	for(int i = 0; i < 2; i++){
		int res = (i == 0 ? b+c : b*c);
		for(int j = 0; j < 2; j++){
			int aux = (j == 0 ? res + a : res*a);
			maxi = max(maxi, aux);
		}
	}
	cout << maxi << endl;	
    return 0;
}