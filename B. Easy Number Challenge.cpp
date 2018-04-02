#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll md = 1073741824;
ll divisor[1000005];

int main(){
    
    for(int i = 1; i <= 1000000; i++)
        for(int j = i; j <= 1000000; j += i)
            divisor[j]++;

    int a, b, c; cin >> a >> b >> c;

    ll res = 0;

    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= c; k++)
                res = (res%md + divisor[i*j*k]%md)%md;

    cout << res << endl;
    return 0;
}
