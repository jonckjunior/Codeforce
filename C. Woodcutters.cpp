#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

vector<ii> v;

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        v.push_back(ii(x,y));
    }
    sort(v.begin(), v.end());
    int esq = v[0].first, ans = 1 + (n > 1);
    for(int i = 1; i < n-1; i++){
        int l = v[i].first - v[i].second;
        int r = v[i].first + v[i].second;
        if(esq < l && l > v[i-1].first){
            esq = v[i].first;
            ans++;
        }
        else if(r < v[i+1].first){
            esq = r;
            ans++;
        }
    }
    cout << ans << endl;
}
