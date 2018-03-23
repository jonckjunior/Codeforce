#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<ii> res;

int main(){
    int n, d, h; cin >> n >> d >> h;
    bool isValid = true;
    if(h > n || h > d || d >= n || 2 * h < d || (d == 1 && n > 2))
        cout << -1 << endl;
    
    else{
        int k = 2, last = 1;
        bool flag = false;
        for(int i = 0; i < h; i++){
            res.push_back(ii(k-1, k));
            last = k-1;            
            k++;
            flag = true;
        }
        if(!flag)
            isValid = false;
        for(int i = 0; i < n-d-1; i++)            
            res.push_back(ii(last, k++));
        
        for(int i = 0; i < d-h; i++){
            if(i == 0)
                res.push_back(ii(1, k));
            else
                res.push_back(ii(k-1, k));
            k++;
            flag = true;
        }
        if(!flag)
            isValid = false;
    }
    if(!isValid)
        cout << -1 << endl;
    else{
         for(ii p : res)
             cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}
