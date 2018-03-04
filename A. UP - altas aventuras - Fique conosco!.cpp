#include <bits/stdc++.h>
using namespace std;

int sum[1005];

int main(){
	int n;
	while(cin >> n){
		if(n == 0) break;
		vector<int> v;
		for(int i = 1; i <= n; i++){
			int x; cin >> x;
			sum[i] = sum[i-1] + x;
			// printf("sum[%d] = %d\n", i, sum[i]);
			v.push_back(x);
		}
		int res = 1e9;
		for(int i = 1; i <= n; i++){
			res = min(res, abs(sum[i] - (sum[n]-sum[i])));
		}
		cout << res << endl;
	}
	return 0;
}
