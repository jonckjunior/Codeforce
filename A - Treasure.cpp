#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int a=0, b=0, c=0;
    for(char ch : s){
        if(ch == '(') a++;
        if(ch == ')') b++;
        if(ch == '#') c++;
    }
    if(b >= a || c > a-b)
        cout << -1 << endl;
    else{
        string aux = "";
        int k = 0, k2 = a-b;
        for(char ch : s){
            if(ch == '#'){
                k++;
                if(k == c){
                    aux += string(k2, ')');
                }
                else
                    aux += ')', k2--;
            }
            else
                aux += ch;
        }
        k = a-b;
        a = b = 0;
        bool flag = true;
        for(char ch : aux){
            if(ch == '(') a++;
            else b++;
            if(b > a) flag = false;
        }
        if(!flag){
            cout << -1 << endl;
            return 0;
        }
        for(int i = 0; i < c-1; i++, k--)
            cout << 1 << endl;
        cout << k << endl;
    }
    return 0;
}
