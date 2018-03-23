#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, orig; cin >> n;
    int root = sqrt(n);
    vector<int> primos;
    primos.push_back(1);

    orig = n;
    for(int i = 2; i <= root; i++)
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
                primos.push_back(i);
            }
        }
    if(n != 1)
        primos.push_back(n);

    for(int p : primos){
        orig /= p;
        cout << orig << " ";
    }
    cout << endl;
    return 0;
}
