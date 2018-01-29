#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cost[50005][10];
ll tempo[50005][10];

int main(){
    ios::sync_with_stdio(false);
    int n, m;cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> cost[i][j];
    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++){
            tempo[i][j] = max(tempo[i-1][j] , tempo[i][j-1]) + cost[i][j];
        }
    for(int i = 1; i <= n; i++)
        cout << tempo[i][m] << " ";
    cout << endl;
    return 0;
}
