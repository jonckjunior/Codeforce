#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    int res = 1e9;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++)
                for(int l = 0; l <= n; l++){
                    // printf("%d %d %d %d\n", i, j, k, l);
                    // printf("%d %d\n", i+j+k+l, (i*2 + j*3 + k*4 + l*5));
                    if(i+j+k+l == n && (i*2 + j*3 + k*4 + l*5) == m)
                        res = min(res, i);
                }
    cout << res << endl;
    return 0;
}
