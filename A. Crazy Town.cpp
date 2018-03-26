#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y; cin >> x >> y;
    int px, py; cin >> px >> py;
    int n; cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a*x + b*y + c > 0 != a*px + b*py + c > 0)
            res++;
    }
    cout << res << endl;
    return 0;
}
