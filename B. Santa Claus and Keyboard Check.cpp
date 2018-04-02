#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;


int main(){
    string s, t; cin >> s >> t;
    int len = s.size();
    map<char,int> mapa;
    bool flag = true;
    vector<ii> res;
    for(int i = 0; i < len; i++){
        char c1 = s[i], c2 = t[i];
        if(mapa.count(c1)){
            if(mapa[c1] != c2)
                flag = false;
        }
        else{
            mapa[c1] = c2;
            if(c1 != c2)
                res.push_back(ii(c1,c2));
        }
        if(mapa.count(c2)){
            if(mapa[c2] != c1)
                flag = false;
        }
        else
            mapa[c2] = c1;
    }

    if(!flag) cout << -1 << endl;
    else{
        cout << res.size() << endl;
        for(ii par : res)
            printf("%c %c\n", par.first, par.second);
    }

    return 0;
}
