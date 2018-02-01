#include <bits/stdc++.h>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    int k; cin >> k;
    int aux = 0, res = 0;
    for(int i = 1; ; i++){
        int n = i;
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n/=10;
        }
        if(sum == 10){
            aux++;
            if(aux == k){
                res = i;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
