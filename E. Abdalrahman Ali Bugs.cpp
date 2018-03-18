#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vi;

ll freq[300];

int main(){
	ios::sync_with_stdio(false);
	string s; cin >> s;
	for(char c : s)
		freq[c]++;
	ll res = 1e9, xres = 0;
	for(ll x = 2; x <= 100000; x++){
		ll soma = 0;
		for(char c = 'a'; c <= 'z'; c++)
			soma += (freq[c]%x) * freq[c];
		if(soma < res){
			res = soma;
			xres = x;
		}
	}
	cout << xres << endl;
    return 0;
}
