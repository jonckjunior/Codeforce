#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int v[maxn];
vector<int> tree[4*maxn];

int left(int p){return (p << 1);}
int right(int p){return (p << 1) + 1;}

void build(int u, int L, int R){
    if(L == R){
        tree[u].push_back(v[L]);
    }
    else{

        int mid = (L+R)/2;
        build(left(u), L, mid);
        build(right(u), mid+1, R);

        vector<int>& v1 = tree[left(u)];
        vector<int>& v2 = tree[right(u)];

        int pos_A = 0, pos_B = 0;
        for(int i = L; i <= R; i++){
            if(pos_A >= v1.size())
                tree[u].push_back(v2[pos_B++]);
            else if(pos_B >= v2.size())
                tree[u].push_back(v1[pos_A++]);
            else if(v1[pos_A] < v2[pos_B])
                tree[u].push_back(v1[pos_A++]);
            else
                tree[u].push_back(v2[pos_B++]);
        }
    }
}

int query(int u, int L, int R, int i, int j, int x){
    // |--------|    |---------------|
    // L        R    i               j
    // |--------|         |-----------|
    // i        j         L           R
    if(R < i || j < L) return 0;

    // |------------------|
    // i      L      R    j

    if(i <= L && R <= j)
        return tree[u].end() - lower_bound(tree[u].begin(), tree[u].end(), x);
    else{
        int mid = (L+R)/2;
        int esq = query(left(u), L, mid, i, j, x);
        int dir = query(right(u), mid+1, R, i, j, x);
        return esq + dir;
    }
}

int main(){
    ios::sync_with_stdio(false);

    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] = min(v[i], n);
    }

    build(1, 1, n);

    long long int res = 0;

    for(int i = 1; i <= n; i++)
        res += query(1, 1, n, i+1, v[i], i);
    cout << res << endl;

    return 0;
}
