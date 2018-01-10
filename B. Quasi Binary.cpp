#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int len[1000005];
int dp[1000005];
vi num;

string s;
int n;

void gerarNum(int val){
    if(val > n) return;
    num.push_back(val);
    gerarNum(val*10);
    gerarNum(val*10+1);
}

int main() {
    cin >> s;
    n = stoi(s);
    gerarNum(1);
    sort(num.begin(), num.end());
    len[1] = 1;
    len[0] = 0;
    dp[1] = 1;
    dp[0] = 0;
    for(int i = 2; i <= n; i++){
        len[i] = 1e9;
        int x = 0;
        for(int j = 0; j < (int)num.size(); j++){
            if(i-num[j] < 0) break;
            if(len[i-num[j]]+1 < len[i]){
                len[i] = len[i-num[j]]+1;
                x = num[j];
            }
        }
        dp[i] = x;
    }
    cout << len[n] << endl;
    for(int i = n; dp[i] != 0; i = i - dp[i])
        cout << dp[i] << " ";
    cout << endl;
    return 0;
}
