#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    string s = "abcd";
    
    for(int i = 4; i < n; i++)
        s += s[i-4];
    cout << string(s.begin(), s.begin()+n) << endl;
    return 0;
}
