#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long int esq = -1e9 -5, dir = 1e9 + 5;
    bool flag = true;
    for(int i = 0; i < n; i++){
        string op; cin >> op;
        long long int num; cin >> num;
        string ans; cin >> ans;
        if(op == ">=" and ans == "Y" || op == "<" and ans == "N")
            esq = max(esq,num);
        if(op == ">=" and ans == "N" || op == "<" and ans == "Y")
            dir = min(dir,num-1);
        if(op == "<=" and ans == "Y" || op == ">" and ans == "N")
            dir = min(dir,num);
        if(op == "<=" and ans == "N" || op == ">" and ans == "Y")
            esq = max(esq,num+1);
        if(esq > dir)
            flag = false;
    }
    if(flag)
        cout << esq << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
