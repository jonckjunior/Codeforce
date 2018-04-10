#include <bits/stdc++.h>
using namespace std;

int cntA[500], cntB[500];

int main(){
    ios::sync_with_stdio(false);

    string a; cin >> a;
    string b; cin >> b;

    for(char c : a)
        cntA[c]++;
    for(char c : b)
        cntB[c]++;
    set<char> S;
    for(char c : b)
        S.insert(c);
    int res = 0;
    for(char c : S){
        if(min(cntA[c], cntB[c]) == 0){
            res = 0;
            break;
        }
        else
            res += min(cntA[c], cntB[c]);
    }
    cout << (res == 0 ? -1 : res) << endl;
    return 0;
}
