#include <bits/stdc++.h>

using namespace std;

const int MAXI = 1e5+5, MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

ll dp[MAXI], sum[MAXI], tree[MAXI*4];

int left(int p){return (p << 1);}
int right(int p){return (p << 1) + 1;}


void build(int p, int L, int R){
    if(L == R) tree[p] = dp[L];
    else{
        int mid = (L+R)/2;
        build(left(p), L, mid);
        build(right(p), mid+1, R);
        tree[p] = (tree[left(p)]%MOD + tree[right(p)]%MOD)%MOD;
    }
}

int query(int p, int L, int R, int i, int j){
    if(L >= i && R <= j) return tree[p];
    if(L > j || R < i) return 0;
    int mid = (L+R)/2;
    int esq = query(left(p), L, mid, i, j);
    int dir = query(right(p), mid+1, R, i, j);
    return (esq%MOD + dir%MOD)%MOD;
}

int main(){
    int n, k; cin >> n >> k;
    dp[1] = 1;
    dp[k] += 1;
    for(int i = 1; i <= MAXI; i++){
        dp[i+1] = (dp[i+1]%MOD + dp[i]%MOD)%MOD;
        if(i+k <= MAXI)
            dp[i+k] = (dp[i+k]%MOD + dp[i]%MOD)%MOD;
    }
    
    build(1,1,MAXI-1);
    
    for(int i = 0; i < n; i++){
        int l,r; cin >> l >> r;
        cout << query(1,1,MAXI-1,l,r) << endl;
    }
    return 0;
}
