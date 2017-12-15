#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int mini = 1e9;
	for(int i = 0; i < m; i++){
		if(i+n-1 >= m) break;
		else mini = min(mini, abs(v[i] - v[i+n-1]));
	}
	cout << mini << endl;
    return 0;
}