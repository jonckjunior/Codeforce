#include <bits/stdc++.h>
using namespace std;

int mat[105][105], res[105][105], res2[105][105];

int main(){
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    vector<string> vs, vs2;

    for(int i = 0; i < n; i++){
        int mini = 1e9;
        for(int j = 0; j < m; j++)
            mini = min(mini, mat[i][j]);
        for(int j = 0; j < mini; j++)
            vs.push_back("row " + to_string(i+1));
        for(int j = 0; j < m; j++)
            res[i][j] += mini;
    }

    for(int j = 0; j < m; j++){
        int mini = 1e9;
        for(int i = 0; i < n; i++)
            mini = min(mini, mat[i][j]-res[i][j]);
        for(int i = 0; i < mini; i++)
            vs.push_back("col " + to_string(j+1));
        for(int i = 0; i < n; i++)
            res[i][j] += mini;
    }


    for(int j = 0; j < m; j++){
        int mini = 1e9;
        for(int i = 0; i < n; i++)
            mini = min(mini, mat[i][j]);
        for(int i = 0; i < mini; i++)
            vs2.push_back("col " + to_string(j+1));
        for(int i = 0; i < n; i++)
            res2[i][j] += mini;
    }

    for(int i = 0; i < n; i++){
        int mini = 1e9;
        for(int j = 0; j < m; j++)
            mini = min(mini, mat[i][j]-res2[i][j]);
        for(int j = 0; j < mini; j++)
            vs2.push_back("row " + to_string(i+1));
        for(int j = 0; j < m; j++)
            res2[i][j] += mini;
    }
    

    bool flag = true, flag2 = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] != res[i][j])
                flag = false;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] != res2[i][j])
                flag2 = false;

    if(flag || flag2){
        if(flag && flag2){
            if(vs2.size() < vs.size())
                swap(vs,vs2);
            cout << vs.size() << endl;
            for(string s : vs)
                cout << s << endl;
        }
        else if(flag){
            cout << vs.size() << endl;
            for(string s : vs)
                cout << s << endl;
        }
        else{
            cout << vs2.size() << endl;
            for(string s : vs2)
                cout << s << endl;
        }
    }
    else
        cout << -1 << endl;
    return 0;
}
