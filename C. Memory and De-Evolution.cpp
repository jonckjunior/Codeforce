#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int y, x; cin >> y >> x;
    int res = 0, turn = 0;
    int a, b, c;
    a = b = c = x;
    while(!(a == b && b == c && c == y)){
        if(turn == 0)
            a = min(y, b+c-1);
        if(turn == 1)
            b = min(y, a+c-1);
        if(turn == 2)
            c = min(y, a+b-1);
        turn++;
        turn %= 3;
        res++;
    }
    cout << res << endl;
    return 0;
}
