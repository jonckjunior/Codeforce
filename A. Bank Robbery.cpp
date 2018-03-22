#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
	int pos, esq, dir; cin >> pos >> esq >> dir;
	int n; cin >> n;

	vi v;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int R = upper_bound(v.begin(), v.end(), dir-1) - v.begin();
	int L = upper_bound(v.begin(), v.end(), esq) - v.begin();
	cout << R-L << endl;
	return 0;
}
