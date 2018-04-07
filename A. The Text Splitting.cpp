#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    int n, p, q; cin >> n >> p >> q;
    string s; cin >> s;
    
    int a = n / p;
    int x = 0, y = -1;
    for (int i = 0; i < a; ++i) {
        int k = i * p;
        if ((n - k) % q == 0) {
            y = (n - k) / q;
            break;
        }
        ++x;
    }
    if (y == -1) {
        x = -1, y = 0;
        a = n / q;
        for (int i = 0; i < a; ++i) {
            int k = i * q;
            if ((n - k) % p == 0) {
                x = (n - k) / p;
                break;
            }
            ++y;
        }
    }
    /*
    
    int esq = 0, dir = 0;
    for(int i = 0; i < )
    
    */
    
    if (x == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << x + y << endl;
    for(int i = 0; i < x; i++)
        cout << s.substr(i*p, p) << endl;
    for(int i = 0; i < y; i++)
        cout << s.substr(p*x + i*q, q) << endl;
    
    return 0;
}
