#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r,x,y,k; cin >> l >> r >> x >> y >> k;
    int p1 = l, p2 = x;
    while(p1 <= r && p2 <= y){
        double res = (double)p1/p2;
        if(res == k){
            cout << "YES" << endl;
            return 0;
        }
        else if(res < k){
            p1++;
        }
        else{
            p2++;
        }
    }
    cout << "NO" << endl;
    return 0;
}
