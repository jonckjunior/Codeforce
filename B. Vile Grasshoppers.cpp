#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, y; cin >> p >> y;
  
    /* 5 50 */
    
    for(int i = y; i > p; i--){
        int root = sqrt(i);
        bool flag = true;
        for(int j = 2; j <= root; j++)
            if(i%j == 0 && j <= p)
                flag = false;
        if(flag){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;    
    return 0;
}
