#include <bits/stdc++.h>
using namespace std;

int v[200005], cnt[200005];

int main(){
    ios::sync_with_stdio(false);    
    
    int n; cin >> n;
    vector<int> mark(n + 1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    
    int op = 0;
    for(int i = 1; i <= n; i++)
        if(cnt[i] > 1)        
            op+= cnt[i]-1;
    
    cout << op << endl;
    
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            while (cnt[v[k]] == 1 || (cnt[v[k]] > 1 && !mark[v[k]] && i > v[k])) {
                mark[v[k]] = 1;
                ++k;
            }
            --cnt[v[k]];
            v[k] = i;
            ++cnt[v[k]];
        }
    }
    for (int i = 0; i < n; ++i) 
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
