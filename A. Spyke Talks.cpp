#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<int> v;
map<int,int> mapa;

int main(){
    
    int n; cin >> n;
    bool flag = true;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mapa[x]++;
    }
    
    int res = 0;
    
    for(ii par : mapa)
        if(par.first != 0 && par.second > 2)
            flag = false;
        else if(par.first != 0 && par.second == 2)
            res++;
    
    if(flag)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}
