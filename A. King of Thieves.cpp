#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    bool flag = false;
    for(int i = 0; i < n; i++) if(s[i] == '*')
        for(int j = 1; j < n; j++){
            bool aux = true;
            for(int k = 1; k <= 4; k++){
                if(i+j*k >= n || s[i+j*k] == '.')
                    aux = false;
            }
            if(aux) flag = true;
        }
    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
