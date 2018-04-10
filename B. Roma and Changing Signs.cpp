#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ms.insert(x);
    }

    while(k > 0){
        int val = *(ms.begin());
        if(val < 0)
            val = -val, k--;
        else{
            k%=2;
            if(k == 1)
                val = -val, k--;
        }
        ms.erase(ms.begin());
        ms.insert(val);
    }
    
    int sum = 0;
    for(int val : ms)
        sum += val;
    cout << sum << endl;
    return 0;
}
