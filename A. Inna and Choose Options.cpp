#include <bits/stdc++.h>
using namespace std;

int m[6][2]{{1,12},{2,6},{3,4},{4,3},{6,2},{12,1}};

/*
    4
              1
    012345
    OXXXOX
    OOXOOX
    OXOXOXOXOXOX
    XXXXXXXXXXXX
    OOOOOOOOOOOO
*/

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vector<int> v;
        for(int j = 0; j < 6; j++){
            int a = m[j][0], b = m[j][1];
            bool found = false;
            for(int k = 0; k < b; k++){
                bool aux = true;
                for(int l = 0; l < a; l++){
                    int pos = k + l*b;
                    if(s[pos] != 'X') aux = false;
                }
                if(aux == true) found = true;
            }
            if(found) v.push_back(j);
        }
        printf("%d ", (int)v.size());
        for(int pos : v)
            printf("%dx%d ", m[pos][0], m[pos][1]);
        printf("\n");
        
    }
}
