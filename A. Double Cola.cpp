#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
string sf[] = {"weiss","Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

/*

5
15
35

				  1                   2                   3         5
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 
1 2 3 4 5 1 1 2 2 3 3 4 4 5 5 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5 5 5 5
*/

int main() {
	ll n; cin >> n;
	ll aux = 5, res = 0;
	while(n - aux > 0){
		n -= aux;
		aux *= 2;
		res++;
	}
	ll t = aux / 5;
	int pos = ceil((double)n/t);
	cout << sf[pos] << endl;
    return 0;
}