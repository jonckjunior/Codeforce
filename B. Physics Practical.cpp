#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    fstream file;
    ofstream fileout("output.txt");
    file.open("input.txt");
    int n; file >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; file >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int esq = 0, dir = 0, res = 0;
    
    while(dir < n){
        if(v[dir] <= v[esq]*2) res = max(res, dir-esq+1);
        dir++;
        while(v[dir] > v[esq]*2)
            esq++;
    }
    fileout << n-res << endl;
    file.close();
    fileout.close();
    return 0;
}
