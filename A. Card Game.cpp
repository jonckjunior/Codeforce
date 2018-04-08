#include <bits/stdc++.h>
using namespace std;

int solve(char c){
	if(c >= '6' && c <= '9') return (c-'0');
	else if(c == 'T') return 10;
	else if(c == 'J') return 11;
	else if(c == 'Q') return 12;
	else if(c == 'K') return 13;
	else if(c == 'A') return 14;
}

int main(){
    ios::sync_with_stdio(false);
    string suit; cin >> suit;
    string c1, c2; cin >> c1 >> c2;
    char coringa = suit[0];
    int num1 = solve(c1[0]), num2 = solve(c2[0]);
    char naipe1 = c1[1], naipe2 = c2[1];
    if(naipe1 == naipe2 && num1 > num2)
    	cout << "YES" << endl;
    else if(naipe1 == coringa && naipe2 != coringa)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;

    return 0;
}
