#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m; cin >> n >> m;
	int res = 0;
	if(m%2 == 0) res += (m/2)*n;
	else{
		res += (m/2)*n;
		res += n/2;
	}
	cout << res << endl;
	return 0;
}