#include <bits/stdc++.h>
using namespace std;

/*
4
4 4 4 5
5
2 3 4 4 5
*/

int main(){
    ios::sync_with_stdio(false);
    vector<int> boy;
    multiset<int> girl;
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        boy.push_back(x);
    }
    
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        girl.insert(x);
    }
    sort(boy.begin(), boy.end());
    int res = 0;
    for(int i = 0; i < n; i++){
        if(girl.find(boy[i]-1) != girl.end()){
            girl.erase(girl.find(boy[i]-1));
            res++;
        }
        else if(girl.find(boy[i]) != girl.end()){
            girl.erase(girl.find(boy[i]));
            res++;
        }
        else if(girl.find(boy[i]+1) != girl.end()){
            girl.erase(girl.find(boy[i]+1));
            res++;
        }
    }
    
    cout << res << endl;
    return 0;
}
