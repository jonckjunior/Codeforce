#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    list<char> lc;
    int d = 0, r = 0, nd = 0, nr = 0;
    for(char c : s){
        lc.push_back(c);
        if(c == 'D') nd++;
        else         nr++;
    }
    while(nd != 0 && nr != 0){
        for(auto it = lc.begin(); it != lc.end();){
            char c = *it;
            if(c == 'D'){
                if(d >= 0){
                    r--;
                    it++;
                }
                else{
                    nd--;
                    it = lc.erase(it);
                    d++;
                }
                
            }
            else{
                if(r >= 0){
                    d--;
                    it++;
                }
                else{
                    nr--;
                    it = lc.erase(it);
                    r++;
                }
                
            }
        }
        
    }
    if(nd > 0) cout << "D" << endl;
    else       cout << "R" << endl;
}
