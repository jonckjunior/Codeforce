#include <bits/stdc++.h>
using namespace std;

int v[5005];

int main(){

    int n; cin >> n;    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[x]++;
    }

    vector<int> res;
    int maxi = 0;
    for(int i = 1; i <= 5000; i++)
        if(v[i] >= 1){
            maxi = i;
            v[i]--;
            res.push_back(i);
        }
    for(int i = maxi-1; i >= 1; i--)
        if(v[i] >= 1){
            v[i]--;
            res.push_back(i);
        }
    cout << res.size() << endl;
    for(int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}
