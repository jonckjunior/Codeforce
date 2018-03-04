#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	while(cin >> a >> b, a+b != 0){
		double res = 1-(double)b/a;
		printf("%.2f\n", res*100);
	}
	return 0;
}
