#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    for(int i = 0; i < (int)s.size(); i++){
        set<char> setzera;
        int aux = 0;
        for(int j = i; j < i+26 && j < s.size(); j++){
            if(s[j] == '?') aux++;
            else setzera.insert(s[j]);
        }
        if((int)setzera.size() + aux == 26){
            for(int j = i; j < i+26 && j < s.size(); j++){
                if(s[j] == '?'){
                    for(char k = 'A'; k <= 'Z'; k++)
                        if(setzera.find(k) == setzera.end()){
                            setzera.insert(k);
                            s[j] = k;
                            break;
                        }
                }
            }
            for(int j = 0; j < (int)s.size(); j++)
                if(s[j] == '?') s[j] = 'A';
            cout << s << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
