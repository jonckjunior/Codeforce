#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v;
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        v.push_back(x);
    }
    int s2 = 0;
    for(int i = 0; i < n; i++){
        s2 += v[i];
        if(s2*2 >= sum){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}
