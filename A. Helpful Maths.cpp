#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++)
		s[i] = (s[i] == '+' ? ' ' : s[i]);
	istringstream iss(s);
	vector<int> v;
	while(iss >> s){
		v.push_back(stoi(s));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		if(i+1 == v.size())
			printf("%d\n", v[i]);
		else
			printf("%d+", v[i]);
	}
	return 0;
}