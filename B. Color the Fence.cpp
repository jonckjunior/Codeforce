#include <bits/stdc++.h>
using namespace std;

int a[15];
int dp[1000005];
int num[1000005];

int solve(int n){
    if(n <= 0)
        return (n < 0 ? -1e9 : 0);
    if(dp[n] != -1) return dp[n];
    int res = 0, maxi = -1;
    for(int i = 9; i >= 1; i--){
        int aux = solve(n - a[i]) + 1;
        if(aux > res){
            res = aux;
            maxi = i;
        }
    }
    num[n] = maxi;
    return dp[n] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    memset(num, -1, sizeof num);
    int n; cin >> n;
    int ok = 0;
    for(int i = 1; i <= 9; i++){
        cin >> a[i];
        if(n >= a[i]) ok = 1;
    }
    if(ok){
        int res = solve(n);
        for(int i = n; i > 0 && num[i] != -1; i -=a[num[i]]){
            cout << num[i];
            //printf("i = %d\n", i);
            //printf("num = %d\n", num[i]);
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
}
