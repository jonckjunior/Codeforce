#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi v;

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
    	int x; cin >> x;
    	v.push_back(x);
    }
    
    int m; cin >> m;

    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++){
    	int x; cin >> x;
    	int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
    	if(pos == n)
    		cout << "Dr. Samer cannot take any offer :(." << endl;
    	else
    		cout << v[pos] << endl;
    }

    return 0;
}
