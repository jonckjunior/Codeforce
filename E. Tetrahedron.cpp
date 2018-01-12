#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int mod = 1000000007;

vvi matrixMult(vvi m1, vvi m2){
    vvi res(4, vi(4, 0));
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                res[i][j] = (res[i][j]%mod + (m1[i][k]*m2[k][j])%mod)%mod;
    return res;
}

vvi fastPow(vvi m, int n){
    if(n == 1)
        return m;
    vvi res = fastPow(m, n/2);
    res = matrixMult(res, res);
    if(n % 2 != 0)
        res = matrixMult(res, m);
    return res;
}

int main(){
    int n; cin >> n;
    vvi m(4, vi(4, 1));
    for(int i = 0; i < 4; i++)
        m[i][i] = 0;
    vvi res = fastPow(m, n);
    cout << res[3][3] << endl;
}
