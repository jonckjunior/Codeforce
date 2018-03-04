#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, a, b;
	while(cin >> x >> y >> a >> b, x+y+a+b != 0){
		set<int> s;
		for(int i = a; i <= b; i++){
			if(i%x == 0 || i%y == 0)
				s.insert(i);
		}
		cout << s.size() << endl;
	}
	return 0;
}
