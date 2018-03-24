#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> v;

map<int, int> mapa_min, mapa_max;

int main(){

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(mapa_min.count(x) == 0){
            mapa_min[x] = i;
        }
        mapa_max[x] = n-1-i;
        v.push_back(x);
    }

    int q; cin >> q;

    ll esq = 0, dir = 0;
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        esq += mapa_min[x] + 1;
        dir += mapa_max[x] + 1;
    }

    cout << esq << " " << dir << endl;
    return 0;
}
