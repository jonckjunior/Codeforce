#include <bits/stdc++.h>
using namespace std;

vector<string> vs;

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <  n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    int x1=1e9,y1=1e9,x2=0,y2=0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(vs[i][j] == '*'){
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
            }
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++)
            cout << vs[i][j];
        cout << endl;
    }

    return 0;
}
