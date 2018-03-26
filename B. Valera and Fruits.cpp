#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int day[3005];

int main(){
    int n, v; cin >> n >> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        day[a] += b;
    }
    int res = 0;
    for(int i = 1; i <= 3001; i++){
        int d1 = min(day[i-1], v);
        int d2 = min(v-d1, day[i]);
        day[i] -= d2;
        res += d1 + d2;
    }
    cout << res << endl;
    return 0;
}
