#include <bits/stdc++.h>
using namespace std;

map<char, int> mapa;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        mapa.clear();
        string a, b; cin >> a >> b;
        for(char c : b)
            mapa[c]++;
        int res = 0;
        for(char c : a){
            if(mapa[c] > 0){
                res++;
                mapa[c]--;
            }
            else
                break;
        }
        cout << res << endl;
    }
    return 0;
}
