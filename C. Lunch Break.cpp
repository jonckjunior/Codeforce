#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a <= b && a <= c) printf("First\n");
        else if(b <= a && b <= c) printf("Second\n");
        else printf("Third\n");
    }
    return 0;
}
