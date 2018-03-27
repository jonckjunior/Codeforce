#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int A = count(s.begin(), s.end(), 'A');
    int I = count(s.begin(), s.end(), 'I');
    if(I == 0)
        cout << A << endl;
    else if(I == 1)
        cout << I << endl;
    else
        cout << 0 << endl;

    return 0;
}
