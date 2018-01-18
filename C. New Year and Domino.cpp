#include <bits/stdc++.h>
using namespace std;

int hor[505][505], ver[505][505];

/*
5 8
....#..#
.#......
##.#....
##..#.##
........
4
1 1 2 3
4 1 4 1
1 2 4 5
2 5 5 8
*/

int main(){
    int n,m; cin >> n >> m;
    vector<string> vs;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++){
            hor[i][j] = hor[i][j-1] + (vs[i][j-1] == '.' && vs[i][j] == '.');
            //printf("hor[%d][%d] = %d\n", i,j, hor[i][j]);
        }
    for(int i = 0; i < m; i++)
        for(int j = 1; j < n; j++){
            ver[j][i] = ver[j-1][i] + (vs[j-1][i] == '.' && vs[j][i] == '.');
            //printf("ver[%d][%d] = %d\n", i,j, ver[i][j]);
        }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--;y1--;x2--;y2--;
        int res = 0;
        for(int i = x1; i <= x2; i++)
            res += hor[i][y2] - hor[i][y1];
        for(int j = y1; j <= y2; j++)
            res += ver[x2][j] - ver[x1][j];
        cout << res << endl;
    }
}
