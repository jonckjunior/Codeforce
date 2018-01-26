#include <bits/stdc++.h>
using namespace std;

/*
    OCOCCCCiCOCCCOi
*/

int main(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> setzera;
    for(int i = 0; i < (int)s.size(); i++)
        setzera.insert(s[i]);
    int dist = setzera.size();
    
    int esq = 0, dir = 0, res = 1e9;
    map<char,int> mapa;
    while(dir < n){
        mapa[ s[dir] ]++;
        
        if(mapa.size() == setzera.size())
            res = min(res, dir-esq+1);
        while(mapa[ s[esq] ] > 1){
            mapa[ s[esq] ]--;
            esq++;
        }
        if(mapa.size() == setzera.size())
            res = min(res, dir-esq+1);
        //printf("%d %d\n", esq, dir);
        dir++;
    }
    cout << res << endl;
    return 0;
}
