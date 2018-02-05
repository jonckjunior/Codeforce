#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<string> vs;
vector<vi> adj, revadj;

vi visited, res;
bool cycle;

void solve(int u){
    visited[u] = 2;
    for(int viz : adj[u]){
        if(!visited[viz])
            solve(viz);
        else if(visited[viz] == 2)
            cycle = true;
    }
    visited[u] = 1;
}

void solve2(int u){
    visited[u] = 1;
    for(int viz : revadj[u])
        if(!visited[viz])
            solve2(viz);
    printf("%c",u);
}

int main(){
    //ios::sync_with_stdio(false);
    
    int n; cin >> n;
    adj.assign(300, vi());
    revadj.assign(300, vi());
    visited.assign(300, 0);
    cycle = false;
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    
    for(int i = 0; i < n-1; i++){
        int mini = min(vs[i].size(), vs[i+1].size());
        for(int j = 0; j < mini; j++){
            char u = vs[i][j], v = vs[i+1][j];
            if(u != v){
                adj[u].push_back(v);
                revadj[v].push_back(u);
                break;
            }
            else if(j+1 == mini && vs[i].size() > vs[i+1].size())
                cycle = true;
        }
    }

    
    for(int i = 'a'; i <= 'z'; i++)
        if(!visited[i])
            solve(i);
    
    if(cycle) cout << "Impossible" << endl;
    else{
        visited.assign(300, 0);
        for(int i = 'a'; i <= 'z'; i++)
            if(!visited[i])
                solve2(i);
        cout << endl;
    }
    
    return 0;
}
