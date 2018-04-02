#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll v[100005], t[100005], aux[100005];

int main(){
    ll n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    for(int i = 1; i <= n; i++)
        aux[i] = aux[i-1] + t[i-1];
    
    multiset<ll> ms;
    
    for(int i = 1; i <= n; i++){
        ll k = aux[i] + t[i];
        ms.insert(v[i] + aux[i]);
        //cout << "retirando " << k << endl;
        ll a = 0;
        while(!ms.empty() && *(ms.begin()) <= k){
            //cout << "retirando " << k << endl;
            //cout << "matou " << *(ms.begin()) << endl;
            a += *(ms.begin()) - aux[i];
            ms.erase(ms.begin());
        }
        a += t[i]*ms.size();
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
