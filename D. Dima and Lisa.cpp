#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    int root = sqrt(x)+1;
    for(int i = 2; i <= root; i++)
        if(x%i == 0)
            return false;
    return true;
}

int main(){
    int n; cin >> n;
    if(isPrime(n)){
        cout << 1 << endl;
        cout << n << endl;
    }
    else{
        for(int i = n; i >= 0; i--) if(isPrime(i)){
            int dif = n-i;
            if(isPrime(dif)){
                cout << 2 << endl;
                cout << i << " " << dif << endl;
                return 0;
            }
            for(int j = 2; j <= dif; j++)
                for(int k = 2; j+k <= dif; k++)
                    if(j+k == dif && isPrime(j) && isPrime(k)){
                        cout << 3 << endl;
                        cout << i << " " << j << " " << k << endl;
                        return 0;
                    }
        }
    }
    return 0;
}
