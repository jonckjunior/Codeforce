#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n; cin >> n;
    vector<int> v;
    int mini = 1e9;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mini = min(mini, x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    int val = v.back(); v.pop_back();
    if(val == 1)
        v.push_back(mini+1);
    else
        v.push_back(1);
    sort(v.begin(), v.end());
    
    for(int val : v)
        cout << val << " ";
    cout << endl;
    return 0;
}
