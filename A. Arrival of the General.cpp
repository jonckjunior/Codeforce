#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	int n; cin >> n;
	int posm, maxi=0, posmin, mini=1e9, res=0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x > maxi){
			maxi = x;
			posm = i;
		}
		v.push_back(x);
	}

	for(int i = posm; i > 0; i--){
		swap(v[i], v[i-1]);
		res++;
	}
	for(int i = 0; i < n; i++){
		if(v[i] <= mini){
			mini = v[i];
			posmin = i;
		}
	}
	res += n-posmin-1;
	cout << res << endl;
    return 0;
}