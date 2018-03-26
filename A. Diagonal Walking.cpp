#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int d = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'R' and s[i+1] == 'U' || s[i] == 'U' and s[i+1] == 'R')
            d++,i++;
    }
    cout << n-d << endl;
    return 0;
}
