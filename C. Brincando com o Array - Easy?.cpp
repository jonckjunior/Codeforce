#include <bits/stdc++.h>
using namespace std;


int main(){
	int n, k;
	while(cin >> n >> k, n+k != 0){
		vector<int> v;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			v.push_back(x);
		}
		sort(v.rbegin(), v.rend());
		k--;
		cout << v[k] << endl;
	}
	return 0;
}
