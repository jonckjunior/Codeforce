#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int v[1005];
bool found;

void solve(int balance, int weight, int last){
    if(found) return;
    if(weight == n){
        found = true;
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    else{
        for(int i = balance + 1; i <= 10; i++)
            if(s[i] == '1' && i != last){
                v[weight] = i;
                solve(i-balance, weight+1, i);
            }
    }
}

int main(){
    cin >> s;
    s = "!" + s;
    cin >> n;
    found = false;
    solve(0,0,0);
    if(!found) cout << "NO" << endl;
    return 0;
}
