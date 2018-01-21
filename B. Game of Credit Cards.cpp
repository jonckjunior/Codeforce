#include <bits/stdc++.h>
using namespace std;

int used[1005];

int main(){
    int n; cin >> n;
    string a,b; cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int pos = 0, maxflick = 0, minflick = 0;
    for(int i = 0; i < n; i++){
        while(pos < n && a[i] >= b[pos])
            pos++;
        if(pos >= n) break;
        pos++;
        maxflick++;
    }
    pos = 0;
    for(int i = 0; i < n; i++){
        while(pos < n && a[i] > b[pos])
            pos++;
        if(pos >= n) break;
        pos++;
        minflick++;
    }
    
    cout << n-minflick << endl;
    cout << maxflick << endl;
}
