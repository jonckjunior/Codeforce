#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
map<string,int> mapa;

int main(){
    int t; cin >> t;
    while(t--){
        mapa.clear();
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            string a, b; cin >> a >> b;
            mapa[b]++;
        }
        string res;
        int maxi = 0;
        for(pair<string,int> par: mapa)
            if(par.second > maxi){
                maxi = par.second;
                res = par.first;
            }
        cout << res << endl;
    }
    return 0;
}
