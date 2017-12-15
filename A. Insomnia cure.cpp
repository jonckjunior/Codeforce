#include <bits/stdc++.h>

using namespace std;

int v[100005];

int main() {
	int a,b,c,d,n; cin >> a >> b >> c >> d >> n;
	int res = 0;
	for(int i = a; i <= n; i+=a)
		v[i] = 1;
	for(int i = b; i <= n; i+=b)
		v[i] = 1;
	for(int i = c; i <= n; i+=c)
		v[i] = 1;
	for(int i = d; i <= n; i+=d)
		v[i] = 1;
	for(int i = 1; i <= n; i++){
		if(v[i]) res++;
	}
	printf("%d\n", res);
    return 0;
}