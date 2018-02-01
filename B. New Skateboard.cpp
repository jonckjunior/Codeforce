#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

string s;
int len, v[300005];

int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    len = s.size();
    ll res = 0;
    for(int i = 0; i < len; i++)
        v[i] = s[i]-'0';
    for(int i = 0; i < len; i++)
        res += (v[i]%4==0);
    for(ll i = 0; i < len-1;i++){
        if((v[i]*10 + v[i+1])%4 == 0)
            res += i+1;
    }
    cout << res << endl;
    return 0;
}
