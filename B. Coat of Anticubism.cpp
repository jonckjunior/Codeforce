#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    ll sum = 0;
    for(int i = 0; i < n-1; i++)
        sum += v[i];
    
    cout << abs(v.back() - sum) + 1 << endl;
    
    return 0;
}
