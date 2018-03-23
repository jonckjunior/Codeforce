#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int res = 0;
    vector<char> v;
    for(int c : s){
        if(!v.empty() && v.back() == c){
            v.push_back(c);
            if(v.size() == 5){
                v.clear();
                res++;
            }
        }
        else if(v.empty()){
            v.push_back(c);
        }
        else{
            v.clear();
            res++;
            v.push_back(c);
        }
    }
    if(!v.empty())
        res++;
    cout << res << endl;
    return 0;
}
