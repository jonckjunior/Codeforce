#include <bits/stdc++.h>

using namespace std;

int v[105];

int main(){
	string ss;
	cin >> ss;
	for(int i = 0; i < (int)ss.size(); i++){
		char c = toupper(ss[i]);
		if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') ss.erase(ss.begin()+i), i--;
		else{
			ss[i] = tolower(ss[i]);
			ss.insert(i, ".");
			i++;
		}
	}
	cout << ss << endl;
}