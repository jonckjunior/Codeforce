#include <bits/stdc++.h>
using namespace std;

map<char, int> mapa;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int a, b; cin >> a >> b;
        if(a%2 == 0 && b%2 == 0)
            cout << "abdullah" << endl;
        else
            cout << "hasan" << endl;
    }
    return 0;
}
