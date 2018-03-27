#include <bits/stdc++.h>
using namespace std;

int v[100005];

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    bool flag = true;
    for(int i = 1; i < n; i++)
        if(v[i] % k != v[0] % k)
            flag = false;
    if(flag){
        int mini = *min_element(v, v+n);
        long long int res = 0;
        for(int i = 0; i < n; i++)
            res += (v[i]-mini)/k;
        cout << res << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
