#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'L') x--;
        else if(s[i] == 'R') x++;
    }
    
    cout << n - (abs(x) + abs(y)) << endl;
    return 0;
}
