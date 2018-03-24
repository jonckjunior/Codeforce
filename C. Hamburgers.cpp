#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll need[5], have[5], price[5];

int main(){
    string s; cin >> s;
    for(char c : s){
        if(c == 'B') need[0]++;
        if(c == 'S') need[1]++;
        if(c == 'C') need[2]++;
    }

    for(int i = 0; i < 3; i++)
        cin >> have[i];
    for(int i = 0; i < 3; i++)
        cin >> price[i];
    ll money; cin >> money;

    ll esq = 0, dir = 1e14+5, res = 0;

    while(esq < dir){
        ll mid = (esq+dir)/2;
        ll p = 0;
        for(int i = 0; i < 3; i++)
            if(need[i]*mid > have[i])
                p += (need[i]*mid-have[i])*price[i];
        if(p < money)
            esq = mid+1;
        else
            dir = mid;
        if(p <= money)
            res = max(res, mid);
    }
    cout << res << endl;
    return 0;
}
