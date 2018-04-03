#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mat[2005][2005], principal[2005][2005], secundaria[2005][2005];

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    for(int j = 0; j < n; j++){
        ll aux = 0;
        for(int k = 0; k < n && j+k < n; k++)
            aux += mat[0+k][j+k];
        for(int k = 0; k < n && j+k < n; k++)
            principal[0+k][j+k] = aux;
    }
    
    for(int i = 1; i < n; i++){
        ll aux = 0;
        for(int k = 0; i+k < n && k < n; k++)
            aux += mat[i+k][0+k];
        for(int k = 0; i+k < n && k < n; k++)
            principal[i+k][0+k] = aux;
    }
    
    for(int j = 0; j < n; j++){
        ll aux = 0;
        for(int k = 0; 0+k < n && j-k >= 0; k++)
            aux += mat[0+k][j-k];
        for(int k = 0; 0+k < n && j-k >= 0; k++)
            secundaria[0+k][j-k] = aux;
    }
    
    for(int i = 1; i < n; i++){
        ll aux = 0;
        for(int k = 0; i+k < n && n-1-k >= 0; k++)
            aux += mat[i+k][n-1-k];
        for(int k = 0; i+k < n && n-1-k >= 0; k++)
            secundaria[i+k][n-1-k] = aux;
    }
    
    ll b1 = 0, b2 = 0;
    ll x1=1, y1=1, x2=1, y2=2;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if( (i+j)%2 == 0 && principal[i][j]+secundaria[i][j]-mat[i][j] > b1 ){
                b1 = principal[i][j]+secundaria[i][j]-mat[i][j];
                x1 = i+1;
                y1 = j+1;
                
            }
            if( (i+j)%2 == 1 && principal[i][j]+secundaria[i][j]-mat[i][j] > b2 ){
                b2 = principal[i][j]+secundaria[i][j]-mat[i][j];
                x2 = i+1;
                y2 = j+1;
            }
        }
    
    cout << b1 + b2 << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    return 0;
}
