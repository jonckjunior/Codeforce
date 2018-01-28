#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int c[5];
int vis[205][205][205];
string dp[205][205][205];

string solve(int R, int G, int B){
    if(R+G+B < 2){
        if(R > 0) return "R";
        if(G > 0) return "G";
        if(B > 0) return "B";
    }
    if(vis[R][G][B] == 1) return dp[R][G][B];
    vis[R][G][B] = 1;
    string res = "";
    if(R > 0 && G > 0) res += solve(R-1, G-1, B+1);
    if(R > 0 && B > 0) res += solve(R-1, G+1, B-1);
    if(G > 0 && B > 0) res += solve(R+1, G-1, B-1);
    if(R > 1) res += solve(R-1, G, B);
    if(G > 1) res += solve(R, G-1, B);
    if(B > 1) res += solve(R, G, B-1);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return dp[R][G][B] = res;
}

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'R') c[0]++;
        if(s[i] == 'G') c[1]++;
        if(s[i] == 'B') c[2]++;
    }
    string res = solve(c[0], c[1], c[2]);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res << endl;
    return 0;
}
