#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int mat[3][10], used[1005];

int adj[5][15];

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            int x; cin >> x;
            mat[i][x] = 1;
            adj[i][j] = x;
        }
    }
    
    set<int> S;
    for(int i = 0; i < 6; i++){
        int x = adj[0][i];
        S.insert(x);
        for(int j = 0; j < 6 && n >= 2; j++){
            int y = adj[1][j];
            S.insert(y);
            S.insert(y*10+x);
            S.insert(x*10+y);
            for(int k = 0; k < 6 && n >= 3; k++){
                int z = adj[2][k];
                S.insert(z);
                S.insert(100*x+10*y+z);
                S.insert(100*x+10*z+y);
                S.insert(100*y+10*x+z);
                S.insert(100*y+10*z+x);
                S.insert(100*z+10*x+y);
                S.insert(100*z+10*y+x);
                S.insert(x*10+z);
                S.insert(z*10+x);
                S.insert(y*10+z);
                S.insert(z*10+y);
            }
        }
    }
    int last = 0, res = 0;
    for(int val : S){
        // cout << val << endl;
        used[val] = 1;
    }
    for(int i = 1; ; i++)
        if(!used[i]){
            cout << i-1 << endl;
            break;
        }
    int i = 0;
    for (i = 1; i < 1000; ++i) {
        int a = i % 10;
        int b = (i / 10) % 10;
        int c = (i / 100) % 10;
        
    }
    
    //cout << i << endl;
    
    return 0;
}
