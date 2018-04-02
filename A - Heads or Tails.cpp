#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    
    int x, y, a, b; cin >> x >> y >> a >> b;
    vector<ii> v;
    for(int i = a; i <= x; i++)
        for(int j = b; j < i && j <= y; j++)
            v.push_back(ii(i,j));
    cout << v.size() << endl;
    for(ii par : v)
        cout << par.first << " " << par.second << endl;
    return 0;
}
