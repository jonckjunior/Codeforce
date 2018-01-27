#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);

    int n; cin >> n;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1 || x == 2 || x == 3 || x == 5 || x == 7 || x == 11) cout << -1 << endl;
        else if(x%4 == 0) cout << x / 4 << endl;
        else if(x%4 == 1 && x >= 9) cout << 1+(x-9)/4 << endl;
        else if(x%4 == 2 && x >= 6) cout << 1+(x-6)/4 << endl;
        else if(x%4 == 3 && x >= 15) cout << 2+(x-15)/4 << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}
