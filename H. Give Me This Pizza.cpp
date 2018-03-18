
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


vi v;
vector< multiset<int> > ms;



int main(){
	ios::sync_with_stdio(false);

	int n; cin >> n;
	ms.assign(50+5, multiset<int>());

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back(x);
		ms[x].insert(i);
	}

	for(int i = 0; i < n; i++){
		int x = v[i];
		ms[x].erase(i);
		int res = 1e9, idxres = 1e9;
		for(int j = x+1; j <= 50; j++)
			if(!ms[j].empty()){
				int idx = *(ms[j].begin());
				if(idx < idxres){
					idxres = idx;
					res = j;
				}
			}
		if(idxres == 1e9) cout << -1 << " ";
		else cout << res << " ";
	}
	cout << endl;
    return 0;
}
