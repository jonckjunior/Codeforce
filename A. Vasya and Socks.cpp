#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m; cin >> n >> m;
	int res = 0, s = n;
	while(s > 0){
		s--;
		res++;
		if(res%m == 0) s++;
	}
	cout << res << endl;
    return 0;
}