#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;

    string aux = s;
    sort(aux.begin(), aux.end());
    if(s != aux) cout << "NO" << endl;
    else{
        int numA = count(s.begin(), s.end(), 'a');
        int numB = count(s.begin(), s.end(), 'b');
        int numC = count(s.begin(), s.end(), 'c');
        if ((numC == numA || numC == numB) && numA > 0 && numB > 0 && numC > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
