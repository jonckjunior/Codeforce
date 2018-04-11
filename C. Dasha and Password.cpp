#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> vs;

int solve(int linha, bool cmp(char)){
    int res1 = 1e5, res2 = 1e5;
    for(int j = 0; j <= m/2; j++)
        if(cmp(vs[linha][j])){
            res1 = j;
            break;
        }
    for(int j = m-1, aux = 1; j > m/2; j--, aux++)
        if(cmp(vs[linha][j])){
            res2 = aux;
            break;
        }
    return min(res1, res2);
}

bool func_digit(char c){return isdigit(c);}
bool func_alpha(char c){return isalpha(c);}
bool func_special(char c){return (c == '#' || c == '*' || c == '&');}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    int res = 1e9;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) if(i != j)
            for(int k = 0; k < n; k++) if(j != k){
                int aux = solve(i, func_digit) + solve(j, func_alpha) + solve(k, func_special);
                res = min(res, aux);
            }
    cout << res << endl;
    return 0;
}
