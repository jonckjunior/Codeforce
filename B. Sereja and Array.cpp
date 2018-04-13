#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll v[100005], sum[100005], idx[100005];

int main(){
    cout.sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int k = 0;
    for(int i = 1; i <= m; i++){
        int op; cin >> op;
        if(op == 1){
            int pos, x; cin >> pos >> x;
            v[pos] = x;
            idx[pos] = k;
        }
        else if(op == 2){
            int y; cin >> y;
            k++;
            sum[k] = sum[k-1]+y;
        }
        else{
            int pos; cin >> pos;
            cout << v[pos]+sum[k]-sum[idx[pos]] << endl;
        }
    }

    
    return 0;
}
