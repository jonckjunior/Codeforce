#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005], fa[100005], fb[100005];

/*

    8 1
    aabaabaa
    fa
    12345678
    00111222
    fb
    12234456
    
*/

int main(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    s = "@"+s;
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] + (s[i] == 'a');
        b[i] = b[i-1] + (s[i] == 'b');
        fa[i] = i - a[i];
        fb[i] = i - b[i];
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        int esq = i, dir = n, mid;
        while(esq <= dir){
            mid = (esq+dir)/2;
            //printf("esq = %d, mid = %d, dir = %d\n", esq, mid, dir);
            //printf("fa[%d] = %d\n", mid, fa[mid]);
            //printf("fa[%d] = %d\n", i-1, fa[i-1]);
            if(fa[mid] - fa[i-1] <= k){
                esq = mid+1;
                res = max(res, mid - i + 1);
            }
            else
                dir = mid-1;
        }
        //printf("comecando em %d o maximo que consegue eh %d com a's\n", i, mid);
        esq = i, dir = n;
        while(esq <= dir){
            mid = (esq+dir)/2;
            if(fb[mid] - fb[i-1] <= k){
                esq = mid + 1;
                res = max(res, mid - i + 1);
            }
            else
                dir = mid - 1;
        }
        //printf("comecando em %d o maximo que consegue eh %d com b's\n", i, mid);
    }
    cout << res << endl;
}
