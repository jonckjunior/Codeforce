#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vector<string> vs;

bool valid(int x, int y){
	if(x < 0 || x >= 3 || y < 0 || y >= 3) return false;
	else return true;
}

bool dfs(int u, string& s){
	if(s[u] == '9')
		return true;
	for(int v : adj[u])
		if(s[v] == s[u]+1)
			return dfs(v, s);
	return false;
}

int main(){
    ios::sync_with_stdio(false);
    string s = "";

    adj.assign(10, vi());

    for(int i = 0; i < 3; i++)
    	for(int j = 0; j < 3; j++)
    		for(int dx = -1; dx <= 1; dx++)
    			for(int dy = -1; dy <= 1; dy++)
    				if(valid(i+dx, j+dy))
    					adj[i*3+j].push_back( (i+dx)*3 + (j+dy) );

    for(int i = 0; i < 3; i++){
    	string aux; cin >> aux;
    	s += aux;
    }
    string aux = "123456789";
    int res = 0;
    do{
    	bool flag = true;
    	for(int i = 0; i < 9; i++)
    		if(aux[i] == '1' && !dfs(i, aux))
    			flag = false;
    	if(!flag) continue;
    	int i;
    	for(i = 0; i < 9; i++)
    		if(s[i] != '0' && s[i] != aux[i])
    			break;
    	if(i == 9)
    		res++;
    }while(next_permutation(aux.begin(), aux.end()));
    cout << res << endl;
    return 0;
}
