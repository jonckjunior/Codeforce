#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int digit=0, letter=0, symbol=0;
        for(int i = 0, j = 0; i < (int)s.size(); i++){
            if(isdigit(s[i]))
              digit++;
        }
        for(int i = 0, j = 0; i < (int)s.size(); i++){
            if(isalpha(s[i]))
              letter++;
        }
        for(int i = 0, j = 0; i < (int)s.size(); i++){
            if(s[i] == '@' || s[i] == '?' || s[i] == '!')
                symbol++;
        }
        if(letter < 4)
            cout << "The last character must be a letter." << endl;
        else if(digit  < 4)
            cout << "The last character must be a digit." << endl;
        else if(symbol < 2)
            cout << "The last character must be a symbol." << endl;
        else
            cout << "The last character can be any type." << endl;
    }
    return 0;
}
