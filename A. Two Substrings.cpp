#include <bits/stdc++.h>

using namespace std;

string s;

bool solve(int t){
    int len = s.size();
    if(t == 0){
        int i;
        for(i = 0; i < len-1; i++)
            if(s[i] == 'A' && s[i+1] == 'B'){
                i+=2;
                break;
            }
        for(; i < len-1; i++)
            if(s[i] == 'B' && s[i+1] == 'A')
                return true;
    }
    else{
        int i;
        for(i = 0; i < len-1; i++)
            if(s[i] == 'B' && s[i+1] == 'A'){
                i+=2;
                break;
            }
        for(; i < len-1; i++)
            if(s[i] == 'A' && s[i+1] == 'B')
                return true;
    }
    return false;
}

int main() {
    cin >> s;
    int len = s.size();
    if(solve(0) || solve(1))
        puts("YES");
    else
        puts("NO");
}
