#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);

    vi A,B;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        A.push_back(u);
        B.push_back(v);
    }

    int res = n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && A[i] == B[j])
                res--;
    cout << res << endl;
    return 0;
}
