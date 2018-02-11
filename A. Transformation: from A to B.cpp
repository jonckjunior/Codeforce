#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> res;

bool solve(ll a, ll b){
    if(a == b) return true;
    if(a > b) return false;
    if(solve(a*2, b)){
        res.push_back(a*2);
        return true;
    }
    else if(solve(a*10+1, b)){
        res.push_back(a*10+1);
        return true;
    }
    else
        return false;
}

int main(){
    int a, b; cin >> a >> b;
    bool found = solve(a, b);
    reverse(res.begin(), res.end());
    if(found){
        cout << "YES" << endl;
        cout << res.size() + 1 << endl;
        cout << a << " ";
        for(int x : res)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
