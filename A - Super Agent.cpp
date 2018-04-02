#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    
    vector<string> vs;
    for(int i = 0; i < 3; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    
    bool flag = true;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++){
            if(vs[1+i][1+j] != vs[1-i][1-j])
                flag = false;
        }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
