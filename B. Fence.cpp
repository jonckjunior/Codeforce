#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += v[i];
    int res = sum, pos = 0;
    for(int i = k; i < n; i++){
        int x = i-k;
        sum += v[i] - v[x];
        if(sum < res){
            res = sum;
            pos = x+1;
        }
    }
    cout << pos+1 << endl;
}
