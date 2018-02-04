#include <bits/stdc++.h>
using namespace std;
typedef deque<int> deq;
typedef pair<deq,deq> deqii;
deq p1,p2;
map<deqii, int> vis; 
int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    
    int k1; cin >> k1;
    for(int i = 0; i < k1; i++){
        int x; cin >> x;
        p1.push_back(x);
    }
    
    int k2; cin >> k2;
    for(int i = 0; i < k2; i++){
        int x; cin >> x;
        p2.push_back(x);
    }
    int res = 0, treta = 0;
    while(!p1.empty() && !p2.empty()){
        if(vis[deqii(p1,p2)]){
            treta = 1;
            break;
        }
        vis[deqii(p1,p2)] = 1;
        res++;
        int x = p1.front(), y = p2.front();
        p1.pop_front(); p2.pop_front();
        if(x > y){
            p1.push_back(y);
            p1.push_back(x);
        }
        else{
            p2.push_back(x);
            p2.push_back(y);
        }
    }
    if(treta) cout << -1 << endl;
    else{
        cout << res << " ";
        if(!p1.empty()) cout << "1" << endl;
        else cout << "2" << endl;
    }
    
    return 0;
}
