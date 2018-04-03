#include <bits/stdc++.h>
using namespace std;

int main(){
    double hora, minuto; cin >> hora >> minuto;
    double h, d, c, n; cin >> h >> d >> c >> n;
    double res = 1e9;
    if(hora >= 20){
        c *= 0.8;
        res = ceil(h/n)*c;
    }
    else{
        res = ceil(h/n)*c;
        h += (60-minuto)*d;
        hora++;
        h += (20-hora)*60*d;
        c *= 0.8;
        res = min(res, ceil(h/n)*c );
    }
    printf("%.4f\n", res);
    return 0;
}
