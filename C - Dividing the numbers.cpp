#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int p[60005];

int main(){
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    if(n == 2){
        cout << 1 << endl;
        cout << "1 1" << endl;
        return 0;
    }
    ll sum = n*(n+1);
    sum /= 2LL;
    ll now = 0, esq = 0;
    int g = 0;
    for(ll i = 1; ; i++){
        now += i;
        esq += i;
        p[i] = 1;
        g++;
        if(now == sum/2)
            break;
        if(now > sum/2){
            g--;
            ll dif = now-sum/2;
            p[dif] = 0;
            esq -= dif;
            break;
        }
    }
    cout << abs(esq*2-sum) << endl;
    cout << g << " ";
    for(int i = 1; i <= n; i++)
        if(p[i] == 1)
            cout << i << " ";
    cout << endl;
    return 0;
}
