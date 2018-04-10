#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ll c = ceil(pow(1LL*a*b, 1.0/3.0));
        if((ll)c*c*c == 1LL*a*b && a%c == 0 && b%c == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
