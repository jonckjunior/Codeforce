#include <bits/stdc++.h>
using namespace std;
int len, sum, dp[105][905], dp2[105][905];
vector<int> v,v2;
bool solve(int n, int s){
    if(n == len)
        return (s == sum);
    if(dp[n][s] != -1) return dp[n][s];
    for(int i = 9; i >= (n == 0 ? 1 : 0); i--){
        if(solve(n+1, s+i)){
            v.push_back(i);
            return dp[n][s] = true;
        }
    }
    return dp[n][s] = false;
}

bool solve2(int n, int s){
    if(n == len)
        return (s == sum);
    if(dp2[n][s] != -1) return dp2[n][s];
    for(int i = (n == 0 ? 1 : 0); i <= 9; i++){
        if(solve2(n+1, s+i)){
            v2.push_back(i);
            return dp2[n][s] = true;
        }
    }
    return dp2[n][s] = false;
}

int main() {
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    scanf("%d %d",&len, &sum);
    if(len == 1 && sum == 0){
        printf("0 0\n");
        return 0;
    }
    if(solve(0,0) && solve2(0,0)){
        reverse(v.begin(), v.end());
        reverse(v2.begin(), v2.end());
        for(int i = 0; i < (int)v2.size(); i++)
            printf("%d",v2[i]);
        printf(" ");
        for(int i = 0; i < (int)v.size(); i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else
        printf("-1 -1\n");
}
