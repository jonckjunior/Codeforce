#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int len = s.size();
    for(int i = 0; i < len; i++){
        int a = s[i]-'0';
        if(a%8 == 0){
            puts("YES");
            printf("%d\n", a);
            return  0;
        }
        for(int j = i+1; j < len; j++){
            int b = s[j]-'0';
            if((a*10+b)%8 == 0){
                puts("YES");
                printf("%d%d\n",a,b);
                return 0;
            }
            for(int k = j+1; k < len; k++){
                int c = s[k]-'0';
                if((a*100+b*10+c)%8 == 0){
                    puts("YES");
                    printf("%d%d%d\n",a,b,c);
                    return 0;
                }
           }
        }
    }
    puts("NO");
    
    return 0;
}
