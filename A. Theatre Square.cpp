#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,m,a,res=0;
	cin >> n >> m >> a;
	res = ceil(m/(double)a);
	res = ceil(n/(double)a)*res;
	cout << res << endl;	
}