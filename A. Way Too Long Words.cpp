#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string ss;
	cin >> n;
	while(n--){
		cin >> ss;
		int len = ss.size();
		if(len > 10) printf("%c%d%c\n",ss[0],len-2,ss[len-1]);
		else 	  	 printf("%s\n",ss.c_str());
	}
}