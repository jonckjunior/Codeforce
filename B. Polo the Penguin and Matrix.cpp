#include <bits/stdc++.h>
using namespace std;

int mt[105][105];

int main(){
    ios::sync_with_stdio(false);
    int n,m,d; cin >> n >> m >> d;
    
    set<int> ss;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> mt[i][j];
            ss.insert(mt[i][j]%d);
        }
    if(ss.size() > 1){
        puts("-1");
    }
    else{
        vector<int> v;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                v.push_back(mt[i][j]);
        sort(v.begin(), v.end());
        int k = v.size();
        int res = 0, mediana = v[k/2];
        for(int i = 0; i < v.size(); i++)
            res += abs(v[i] - mediana);
        res/=d;
        cout << res << endl;
    }
    return 0;
}
