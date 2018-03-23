#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 1e6+5;
int h[maxn], m[maxn];

string f1 = "heavy", f2 = "metal";

ll res = 0;
int heavy = 0, metal = 0;

int main(){
    string s;
    cin >> s;
    
    for(int i = 0; i < (int)s.size(); i++){
        if(s.substr(i, f1.size()) == f1){
            heavy++;
        }
        if(s.substr(i, f2.size()) == f2){
            res += heavy;
        }
    }
    
    cout << res << endl;
    
    
    return 0;
}
