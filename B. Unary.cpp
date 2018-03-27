#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<char, string> mapa;

int md = 1000003;

ll modPow(int b, int e){
    if(e == 0) return 1;
    if(e == 1) return b%md;
    ll res = modPow(b, e/2);
    res = (res%md * res%md)%md;
    if(e%2 == 1)
        res = (res%md * b%md)%md;
    return res;
}

int main(){

    mapa['>'] = "1000";
    mapa['<'] = "1001";
    mapa['+'] = "1010";
    mapa['-'] = "1011";
    mapa['.'] = "1100";
    mapa[','] = "1101";
    mapa['['] = "1110";
    mapa[']'] = "1111";

    string s; cin >> s;

    string aux = "";
    for(char c : s)
        aux += mapa[c];

    reverse(aux.begin(), aux.end());
    ll res = 0;
    for(int i = 0; i < (int)aux.size(); i++)
        if(aux[i] == '1')
            res = (res%md + modPow(2,i)%md)%md;
    cout << res << endl;
    return 0;
}
