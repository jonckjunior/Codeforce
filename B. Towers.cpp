#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;


int main(){
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    set<ii> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(ii(x,i+1));
    }

    if(n == 1){
        cout << "0 0" << endl;
        return 0;
    }
    vector<ii> op;
    for(int i = 0; i < k; i++){
        ii mini = *(s.begin()), maxi = *(s.rbegin());
        if(maxi.first - mini.first <= 1)
            break;
        op.push_back( ii(maxi.second, mini.second));
        s.erase(mini); s.erase(maxi);
        mini.first++; maxi.first--;
        s.insert(mini);
        s.insert(maxi);
    }
    int dif = s.rbegin()->first - s.begin()->first;
    cout << dif << " " << op.size() << endl;
    for(ii par : op)
        cout << par.first << " " << par.second << endl;
    return 0;
}
