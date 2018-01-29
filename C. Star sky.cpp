#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mt[105][105][15];
int row[105][105][15];

int main(){
    ios::sync_with_stdio(false);
    int n,q,c; cin >> n >> q >> c;
    for(int i = 0; i < n; i++){
        int x,y,s; cin >> x >> y >> s;
        mt[x][y][s]++;
    }
    
    for(int k = 0; k <= c; k++)
        for(int i = 1; i <= 100; i++)
            for(int j = 1; j <= 100; j++)
                row[i][j][k] = row[i][j-1][k] + mt[i][j][k];
    
    for(int i = 0; i < q; i++){
        int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for(int k = 0; k <= c; k++)
            for(int x = x1; x <= x2; x++)
                res += (row[x][y2][k] - row[x][y1-1][k]) * ((k + t)%(c+1));
        cout << res << endl;
    }
    
    return 0;
}
