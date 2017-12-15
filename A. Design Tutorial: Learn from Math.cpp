#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int maxn = 1e6+5;
bitset<maxn> bt;

void crivo(){
	bt.set();
	bt[0] = bt[1] = 1;
	for(ll i = 2; i <= maxn; i++) if(bt[i]){
		for(ll j = i*i; j <= maxn; j+=i)
			bt[j] = 0;
	}
}


int main() {
	crivo();
	int n; cin >> n;
	for(int i = 2; i <= n; i++){
		if(n-i >= 0 && bt[n-i] == 0 && bt[i] == 0){
			printf("%d %d\n", i, n-i);
			break;
		}
	}
    return 0;
}