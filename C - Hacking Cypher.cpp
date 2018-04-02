#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int validA[1000005], validB[1000005], e10[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int a, b; cin >> a >> b;
    int n = s.size();
    
    e10[0] = 1;
    for(int i = 1; i <= s.size(); i++)
        e10[i] = ( (10%b) * (e10[i-1]%b) )%b;
    
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum*10 + s[i]-'0')%a;
        //printf("pos %d = %d\n", i, sum);
        if(sum == 0)
            validA[i] = 1;
    }
    puts("");
    sum = 0;
    for(int i = n-1, j = 0; i >= 0; i--, j++){
        if(s[i] == '0') continue;
        ll e = (e10[j] * ((s[i]-'0')%b) )%b;
        sum = (sum%b + e%b)%b;
        //printf("pos %d = %d\n", i, sum);
        if(sum == 0)
            validB[i] = 1;
    }
    
    for(int i = 0; i < n-1; i++)
        if(validA[i] && validB[i+1]){
            cout << "YES" << endl;
            for(int j = 0; j <= i; j++)
                cout << s[j];
            cout << endl;
            for(int j = i+1; j < n; j++)
                cout << s[j];
            cout << endl;
            return 0;
        }
    cout << "NO" << endl;
        
    return 0;
}
