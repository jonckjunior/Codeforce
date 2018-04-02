#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s; getline(cin, s);
    bool v = true;
    for(char ch : s){
        if(isalpha(ch)){
            ch = tolower(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                v = true;
            else
                v = false;
        }
    }
    if(v) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
