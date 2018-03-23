#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string str; cin >> str;
    vector<char> vs;

    char last = '!';

    for(char c : str){
        if(!vs.empty() && vs.back() == c)
            vs.pop_back();
        else
            vs.push_back(c);
    }

    if(vs.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
