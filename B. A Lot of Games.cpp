#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct Node{
    int u;
    map<char,int> child;
};

vector<Node> grafo;

int win[100005], lose[100005];

void addTrie(int u, string &s){
    for(char c : s){
        if(grafo[u].child.count(c) == 0){
            Node novo; novo.u = grafo.size();
            grafo[u].child[c] = grafo.size();
            grafo.push_back(novo);
        }
        u = grafo[grafo[u].child[c]].u;
    }
}

void solve(int u){
    if(grafo[u].child.size() == 0){
        win[u] = 0;
        lose[u] = 1;
    }
    for(ii par : grafo[u].child){
        int v = par.second;
        solve(v);
        win[u] = (win[u] || !win[v]);
        lose[u] = (lose[u] || !lose[v]);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    Node root; root.u = 0;
    grafo.push_back(root);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        addTrie(0, s);
    }
    
    solve(0);
    int w = win[0], l = lose[0];
    if(w == 0) cout << "Second" << endl;
    else if(w == 1 && l == 1) cout << "First" << endl;
    else if(w == 1 && l == 0 && k%2 != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
