#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> vs;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    reverse(vs.begin(), vs.end());

    vector<string> res;
    map<string,int> mapa;
    for(string s : vs){
        mapa[s]++;
        if(mapa[s] == 1)
            res.push_back(s);
    }
    for(string s : res)
        cout << s << endl;
    return 0;
}
