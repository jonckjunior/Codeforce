#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

char mt[105][105];
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mt[i][j];
    int t;
    for(int i = 0; i < n; i++){
        t = i%2;
        for(int j = 0; j < m; j++){
            if(mt[i][j] == '.')
                mt[i][j] = (t == 0 ? 'W' : 'B');
            t = !t;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << mt[i][j];
        cout << endl;
    }
    return 0;
}
