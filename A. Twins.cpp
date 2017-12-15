#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v;
	double soma = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		soma += x;
		v.push_back(x);
	}
	if(n == 1){
		printf("1\n");
		return 0;
	}
	sort(v.rbegin(), v.rend());
	soma /= 2;
	int res = 0;
	double aux = 0;
	for(int i = 0; i < v.size(); i++){
		aux += v[i];
		res++;
		if(aux > soma){
			break;
		}
	}
	cout << res << endl;
	return 0;
}