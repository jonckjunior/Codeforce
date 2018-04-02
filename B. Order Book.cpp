#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int vs[100005], vb[100005];

int main(){
    ios::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    
    vector<ii> buy, sell;
    
    for(int i = 0; i < n; i++){
        string op; cin >> op;
        int p, q; cin >> p >> q;
        if(op == "B")
            vb[p] += q;
        else
            vs[p] += q;
    }
    
    for(int i = 0, j = 0; i <= 100000 && j < k; i++)
        if(vs[i] > 0)
            sell.push_back(ii(i, vs[i])), j++;
    for(int i = 100000; i >= 0; i--)
        if(vb[i] > 0)
            buy.push_back(ii(i, vb[i]));
    reverse(sell.begin(), sell.end());
    for(int i = 0; i < (int)sell.size() && i < k; i++)
        cout << "S " << sell[i].first << " " << sell[i].second << endl;
    for(int i = 0; i < (int)buy.size() && i < k; i++)
        cout << "B " << buy[i].first << " " << buy[i].second << endl;
    
    return 0;
}
