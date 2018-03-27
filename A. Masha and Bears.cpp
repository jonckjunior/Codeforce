#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    for(int i = 3; i <= 200; i++)
        for(int j = 2; j < i; j++)
            for(int k = 1; k < j; k++)
                if(a <= i && a*2 >= i && b <= j && b*2 >= j && c <= k && c*2 >= k && d <= k && 2*d >= k && !(d*2 >= i) && !(d*2 >= j)){
                    cout << i << endl;
                    cout << j << endl;
                    cout << k << endl;
                    return 0;
                }
    cout << -1 << endl;
    return 0;
}
