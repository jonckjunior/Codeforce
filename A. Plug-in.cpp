#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    deque<char> dq;
    string s; cin >> s;
    for(char c : s){
        if(!dq.empty() && dq.back() == c)
            dq.pop_back();
        else
            dq.push_back(c);
    }
    for(char c : dq)
        cout << c;
    cout << endl;
    return 0;
}
