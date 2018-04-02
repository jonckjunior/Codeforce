#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 1e7;

int main(){
    int m; cin >> m;
    int cnt2=0, cnt5=0;
    vector<int> res;
    for(int i = 2; i <= maxn; i++){
        int n2 = i, n5 = i;
        while(n2%2 == 0)
            cnt2++, n2 /= 2;
        while(n5%5 == 0)
            cnt5++, n5 /= 5;
        if(min(cnt2, cnt5) == m)
            res.push_back(i);
        if(min(cnt2, cnt5) > m)
            break;
        
    }
    cout << res.size() << endl;
    for(int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
