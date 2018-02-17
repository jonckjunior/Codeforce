#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

string s;
vi v,vres;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        vres.push_back(x);
    }
    cin >> s;
    int pos = 0;
    while(pos < n){
        int esq = pos;
        while(s[pos] == '1')
            pos++;
        pos++;
        //printf("componente de %d a %d\n", esq, pos);
        sort(v.begin()+esq, v.begin()+pos);
    }
    sort(vres.begin(), vres.end());
    if(vres == v) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
