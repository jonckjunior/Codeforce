#include <bits/stdc++.h>
using namespace std;

int used[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; cin >> n >> t;
    string a, b; cin >> a >> b;
    string res = "";

    for(int i = 0; i < n; i++)
        for(char j = 'a'; j <= 'z'; j++)
            if(a[i] != j && b[i] != j){
                res += j;
                break;
            }
    int eq = n-t;

    for(int i = 0; i < n && eq > 0; i++)
        if(a[i] == b[i]){
            res[i] = a[i];
            eq--;
        }
    int eqA = eq, eqB = eq;
    for(int i = 0; i < n && eqA > 0; i++)
        if(a[i] != b[i]){
            res[i] = a[i];
            eqA--;
            used[i] = 1;
        }
    for(int i = 0; i < n && eqB > 0; i++)
        if(a[i] != b[i] && !used[i]){
            res[i] = b[i];
            eqB--;
        }
    if(eqA+eqB == 0) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}
