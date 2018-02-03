#include <bits/stdc++.h>
using namespace std;

int m2[1005][1005], m5[1005][1005];
int dp2[1005][1005], dp5[1005][1005];
int pai2[1005][1005], pai5[1005][1005];

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    int zero = 0, xz, yz;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            dp2[i][j] = dp5[i][j] = 1e9;
            
            int x; cin >> x;
            if(x == 0) x = 2*5, zero = 1, xz = i, yz = j;
            while(x%2==0) m2[i][j]++, x /= 2;
            while(x%5==0) m5[i][j]++, x /= 5;
        }
    int res = 1e9;
    dp2[0][0] = m2[0][0];
    dp5[0][0] = m5[0][0];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(dp2[i][j] + m2[i+1][j] <= dp2[i+1][j]){
                dp2[i+1][j] = dp2[i][j] + m2[i+1][j];
                pai2[i+1][j] = 1;
            }
            if(dp2[i][j] + m2[i][j+1] <= dp2[i][j+1]){
                dp2[i][j+1] = dp2[i][j] + m2[i][j+1];
                pai2[i][j+1] = 0;
            }
            
            if(dp5[i][j] + m5[i+1][j] <= dp5[i+1][j]){
                dp5[i+1][j] = dp5[i][j] + m5[i+1][j];
                pai5[i+1][j] = 1;
            }
            if(dp5[i][j] + m5[i][j+1] <= dp5[i][j+1]){
                dp5[i][j+1] = dp5[i][j] + m5[i][j+1];
                pai5[i][j+1] = 0;
            }
        }
    res = min(dp2[n-1][n-1], dp5[n-1][n-1]);
    
    if(zero == 1 && res >= 1){
        cout << 1 << endl;
        for(int i = 0; i < yz; i++) cout << "R";
        for(int i = 0; i < n-1; i++) cout << "D";
        for(int i = yz; i < n-1; i++) cout << "R";
    }
    else{
        cout << res << endl;
        string ss = "";
        if(dp2[n-1][n-1] < dp5[n-1][n-1]){
            int x = n-1, y = n-1;
            while(x != 0 || y != 0){
                if(pai2[x][y] == 1) ss += "D", x--;
                else ss += "R", y--;
            }
        }
        else{
            int x = n-1, y = n-1;
            while(x != 0 || y != 0){
                if(pai5[x][y] == 1) ss += "D", x--;
                else ss += "R", y--;
            }
        }
        reverse(ss.begin(), ss.end());
        cout << ss << endl;
    }
    
    return 0;
}
