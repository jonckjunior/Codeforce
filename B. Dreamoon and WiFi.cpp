#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int pos;

double solve(int u, int soma){
    if(u == (int)s1.size()){
        return (soma == pos);
    }
    if(s2[u] != '?')
        return solve(u+1, soma + (s2[u] == '+' ? 1 : -1));
    return solve(u+1, soma+1) + solve(u+1, soma-1);
}

int main() {
    cin >> s1 >> s2;
    for(int i = 0; i < (int)s1.size(); i++){
        if(s1[i] == '-') pos--;
        else pos++;
    }
    double bot = 1;
    for(int i = 0; i < (int)s2.size(); i++){
        if(s2[i] == '?')
            bot *= 2;
    }
    double top = solve(0,0);
    printf("%.9f\n", top/bot);
}
