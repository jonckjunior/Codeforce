#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0; i <= 1000; i++){
    	string s = to_string(i);
    	bool found = true;
    	for(int j = 0; j < (int)s.size(); j++){
    		if(s[j] != '4' && s[j] != '7'){
    			found = false;
    		}
    	}
    	if(found){
    		v.push_back(i);    		
    	}
    }
    int n; cin >> n;
    for(int i = 0; i < v.size(); i++)
    	if(n%v[i] == 0){
    		puts("YES");
    		return 0;
    	}
    puts("NO");
    return 0;
}