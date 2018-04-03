#include <bits/stdc++.h>
using namespace std;

int bit(int p){return (1 << p);}

int main(){
    string s; cin >> s;
    int n = s.size();
    string res = "";
    for(int i = 1; i < (1 << n); i++){
        string aux = "";
        for(int j = 0; j < 12; j++)
            if(bit(j)&i)
                aux += s[j];
        bool flag = true;
        for(int j = 0; j < (int)aux.size(); j++)
            if(aux[j] != aux[(int)aux.size() - 1 - j])
                flag = false;
        if(flag && aux > res)
            res = aux;
    }
    cout << res << endl;
    return 0;
}
