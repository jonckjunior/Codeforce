#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,r;
    cin >> a >> b;
    r = a;

    while(1){
        c = floor(a/(double)b);
        r += c;
        if(c == 0) break;
        a = a - c*b;
        a += c;
    }
    
    cout << r << endl;
    return 0;
}