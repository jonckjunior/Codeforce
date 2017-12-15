#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for(int i = 0; i < k; i++){
		string aux = s;
		for(int j = 0; j < n-1; j++)
			if(s[j] == 'B' && s[j+1] == 'G')
				swap(aux[j], aux[j+1]);
		s = aux;
	}
	cout << s << endl;
    return 0;
}