#include <bits/stdc++.h>
using namespace std;

vector<string> vs;
string novaString;
map<string, string> mapa;

void init(int u, int t){
    if(u == t)
        vs.push_back(novaString);
    else{
        for(char i = 'a'; i <= 'f'; i++){
            novaString += i;
            init(u+1, t);
            novaString.pop_back();
        }
    }
}

int solve(string s){
    if(s.size() == 1)
        return (s[0] == 'a');
    else{
        int res = 0;
        string aux = s.substr(0,2);
        if(mapa.count(aux))
            res += solve(mapa[aux] + s.substr(2));
        return res;
    }
}

int main(){
    int n, q; cin >> n >> q;
    novaString = "";
    init(0, n);
    for(int i = 0; i < q; i++){
        string a, b; cin >> a >> b;
        mapa[a] = b;
    }
    int res = 0;
    for(string s : vs){
        res += solve(s);
    }
    cout << res << endl;
    return 0;
}
