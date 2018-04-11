#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int last = -1, k = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '*'){
            last = -1;
            continue;
        }
        if(a > b){
            if(last <= 0 && a > 0) last = 1, k++, a--;
            else if(b > 0)         last = 0, k++, b--;
            else last = -1;
        }
        else{
            if( (last == 1 || last == -1) && b > 0) last = 0, k++, b--;
            else if(a > 0)                          last = 1, k++, a--;
            else last = -1;
        }
    }
    cout << k << endl;
    return 0;
}
