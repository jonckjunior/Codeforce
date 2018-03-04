#include <bits/stdc++.h>
using namespace std;


int main(){
	int b;
	while(cin >> b, b != 0){
		int a1,d1,l1; cin >> a1 >> d1 >> l1;
		int a2,d2,l2; cin >> a2 >> d2 >> l2;
		double atk1 = (a1+d1)/2.0 + (l1%2 == 0 ? b : 0);
		double atk2 = (a2+d2)/2.0 + (l2%2 == 0 ? b : 0);
		if(atk1 > atk2) puts("Dabriel");
		else if(atk2 > atk1) puts("Guarte");
		else puts("Empate");
	}
	return 0;
}
