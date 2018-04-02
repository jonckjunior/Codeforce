#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int bit(int b){return (1LL << b);}
int md = 1e9+7;

ll modPow(ll b, ll e){
    if(e == 0) return 1;
    if(e == 1) return b%md;
    ll res = modPow(b, e/2);
    res = ((res%md) * (res%md) )%md;
    if(e%2 == 1)
        res = ((res%md) * (b%md))%md;
    return res;
}

string toBin(int n){
    string res = "";
    for(int i = 0; i < 6; i++){
        if(bit(i)&n)
            res += "1";
        else
            res += "0";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    map<char,int> mapa;
    for(int i = '0'; i <= '9'; i++)
        mapa[i] = i-'0';
    for(int i = 'A', j = 10; i <= 'Z'; i++, j++)
        mapa[i] = j;
    for(int i = 'a', j = 36; i <= 'z'; i++, j++)
        mapa[i] = j;
    mapa['-'] = 62;
    mapa['_'] = 63;
    
    string s; cin >> s;
    string binRes = "";
    for(char c : s)
        binRes += toBin(mapa[c]);
    int cnt = 0;
    for(char c : binRes)
        if(c == '0') cnt++;
    
    cout << modPow(3, cnt) << endl;
    
    return 0;
}
