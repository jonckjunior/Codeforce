#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

string s;

string solve(int u, vi& vec){
    if(u >= s.size())
        return "-1";
    vec[s[u]-'0']++;
    string res = solve(u+1, vec);
    if(res != "-1")
        return res;
    vec[s[u]-'0']--;
    for(int d = s[u]-'0'-1; d >= (u == 0); d--){
        vec[d]++;
        int numImpar = 0;
        for(int k = 0; k < 10; k++)
            if(vec[k]%2 == 1)
                numImpar++;
        if(numImpar+u+1 <= s.size()){
            res = "";
            for(int i = 0; i < u; i++)
                res += s[i];
            res += to_string(d);
            for(int i = 0; i < (int)s.size()-u-1-numImpar; i++)
                res += "9";
            for(int k = 9; k >= 0; k--)
                if(vec[k]%2 == 1)
                    res += to_string(k);
            return res;
        }
        vec[d]--;
    }
    return "-1";
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;
        vi zero(10, 0);
        string res = solve(0, zero);
        if(res != "-1") cout << res << endl;
        else cout << string((int)s.size()-2, '9') << endl;
    }
    return 0;
}
