#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    vector<ii> v;
    
    int n; cin >> n;
    for(int i = 0; i < n+1; i++){
        int x, y; cin >> x >> y;
        v.push_back(ii(x,y));
    }
    int res = 0;
    for(int i = 0; i < n-1; i++){
        int x1 = v[i].first, y1 = v[i].second;
        int x2 = v[i+1].first, y2 = v[i+1].second;
        int x3 = v[i+2].first, y3 = v[i+2].second;
        if(x1 < x2 && y2 < y3) res++;
        if(x1 > x2 && y2 > y3) res++;
        if(y1 < y2 && x2 > x3) res++;
        if(y1 > y2 && x2 < x3) res++;
    }
    cout << res << endl;
    return 0;
}
