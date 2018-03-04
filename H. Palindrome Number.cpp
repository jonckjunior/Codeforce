#include <bits/stdc++.h>
using namespace std;

char v[1000005];

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        v[n] = '\0';
        for(int i = 0, j = n-1; i <= j; i++, j--){
            if(i == j){
                int d = min(9, k);
                v[i] = d+'0';
                k -= d;
            }
            else{
                int d = min(9, k/2);
                v[i] = v[j] = d+'0';
                k -= d*2;
            }
        }
        if(k != 0 || v[0] == '0') printf("-1\n");
        else printf("%s\n", v);
    }
    return 0;
}
