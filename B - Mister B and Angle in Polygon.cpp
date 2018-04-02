#include <bits/stdc++.h>
using namespace std;

int main(){
    double n, a; cin >> n >> a;
    double res = 1e9, ires = n;
    double aux = 180/n;
    double sum = aux;
    for(int i = n; i >= 3; i--){
        //cout << fabs(a-sum) << endl;
        if( fabs(a-sum) < res ){
            res = fabs(a-sum);
            ires = i;
        }
        sum += aux;
    }
    cout << "1 2 " << ires << endl;
    return 0;
}
