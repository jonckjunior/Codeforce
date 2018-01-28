#include <bits/stdc++.h>
using namespace std;

int mt[1005][1005], col[1005][1005], row[1005][1005], n , m;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mt[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            row[i][j] = row[i][j-1] + mt[i][j];
    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++)
            col[i][j] = col[i-1][j] + mt[i][j];
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(mt[i][j] == 0){
                int aux = 0;
                if(row[i][j-1] >= 1) aux++;
                if(row[i][m]-row[i][j] >= 1) aux++;
                if(col[i][j] >= 1) aux++;
                if(col[n][j] - col[i][j] >= 1) aux++;
                //printf("%d %d achou %d\n", i, j, aux);
                res += aux;
            }
    cout << res << endl;
    return 0;
}
