#include <bits/stdc++.h>
using namespace std;

map<string, string> ipToName;

int main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        string name, ip; cin >> name >> ip;
        ipToName[ip] = name;
    }
    
    for(int i = 0; i < m; i++){
        string op, ip; cin >> op >> ip;
        ip.pop_back();
        string res = op + " " + ip + "; #" + ipToName[ip];
        cout << res << endl;
    }
    return 0;
}
