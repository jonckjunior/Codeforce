#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    double p1_W = (double)a/b, p1_L = 1-p1_W;
    double p2_W = (double)c/d, p2_L = 1-p2_W;
    double coef = 1, res = 0, last = 1;
    while( abs(res-last) > 1e-10 ){
        last = res;
        res += p1_W * coef;
        coef *= (p1_L)*(p2_L);
    }
    
    printf("%.7f\n", res);
    return 0;
}
