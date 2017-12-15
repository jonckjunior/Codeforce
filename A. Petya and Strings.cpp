#include <bits/stdc++.h>

using namespace std;

int main() {
	string a,b; cin >> a >> b;
	for(int i = 0; i < a.size(); i++)
		a[i] = toupper(a[i]);
	for(int i = 0; i < b.size(); i++)
		b[i] = toupper(b[i]);
	int aux = strcmp(a.c_str(), b.c_str());
	if(aux < 0) aux = -1;
	if(aux > 0) aux = 1;
	cout << aux << endl;
	return 0;
}