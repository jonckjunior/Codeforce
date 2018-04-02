#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    
    for(int i = 0; i < n;){
        if(s[i] != '.'){
            i++;
            continue;
        }
        int esq = 0, dir = 0;
        if(i-1 >= 0 && s[i-1] == 'R') esq = 1;
        int pos = i;
        for(i = i+1; i < n; i++)
            if(s[i] != '.'){
                if(s[i] == 'L') dir = 1;
                else dir = 0;
                break;
            }
        if(esq+dir == 2 && (i-pos) % 2 == 1){
            //printf("de %d ate %d com pai\n", i, pos);
            res++;
        }
        if(esq+dir == 0){
            //printf("de %d ate %d sem pai\n", pos, i);
            res+= i-pos;
        }
        i++;
        
    }
    cout << res << endl;
    return 0;
}
