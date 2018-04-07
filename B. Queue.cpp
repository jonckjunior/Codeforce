#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int v[200005], usado[2000005];

int main(){
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> haha(1234567, -1), hehe(1234567, -1);
    
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        usado[x] = usado[y] = 1; 
        haha[x] = y;
        hehe[y] = x;
    }
    int first = 0;
    for(int i = 0; i < 1e6 + 7; i++)
        if(usado[i] && hehe[i] == -1){
            first = i;
            break;
        }
    vector<int> res(n);
    res[0] = first;
    int p = haha[first], k = 2;
    while (p != -1) {
        res[k] = p;
        p = haha[p];
        k += 2;
        if (p == 0) break;
    }
        
    p = haha[0], k = 1;
    while (p != -1) {
        res[k] = p;
        p = haha[p];
        k += 2;
        if (p == 0) break;
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    
    return 0;
}
