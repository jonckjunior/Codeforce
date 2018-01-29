#include <bits/stdc++.h>
using namespace std;

int fib[1005];

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string res = "";
    
    int a = 1, b = 1, c = 2;
    fib[a] = fib[b] = fib[c] = 1;
    while(c <= 1000){
        c = a + b;
        if(c <= 1000) fib[c] = 1;
        a = b;
        b = c;
    }
    for(int i = 1; i <= n; i++){
        if(fib[i]) res += "O";
        else res += "o";
    }
    cout << res << endl;
    return 0;
}
