#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v;

int main() {
    for(int i = 1; i <= 5; i++){
        string aux = "";
        for(int j = 0; j < i; j++)
            aux += "4";
        for(int j = 0; j < i; j++)
            aux += "7";
        do{
            v.push_back(stoll(aux));
        }while(next_permutation(aux.begin(), aux.end()));
    }
    ll n; cin >> n;
    for(ll val : v)
        if(val >= n){
            cout << val << endl;
            break;
        }
    return 0;
}
