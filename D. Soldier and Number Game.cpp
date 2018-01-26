#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll maxn = 5000005;
ll numDiv[maxn + 5], sum[maxn + 5];
bitset<maxn> bt;


int main(){
    ios::sync_with_stdio(false);
    bt.set(); bt[0] = bt[1] = 0;
    
    for(int i = 2; i <= maxn; i++)
        numDiv[i] = 1;
        
    for(ll i = 2; i <= sqrt(maxn); i++) if(numDiv[i] == 1){
        for(ll j = 2; i*j <= maxn; j++)
            numDiv[i*j] = numDiv[j] + 1;
    }
    
    for(int i = 2; i <= maxn; i++)
        sum[i] = sum[i-1] + numDiv[i];
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        cout << sum[a] - sum[b] << endl;
    }
    
    return 0;
}
