#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<string> vs;
    vs.push_back("+------------------------+");
    vs.push_back("|#.#.#.#.#.#.#.#.#.#.#.|D|)");
    vs.push_back("|#.#.#.#.#.#.#.#.#.#.#.|.|");
    vs.push_back("|#.......................|");
    vs.push_back("|#.#.#.#.#.#.#.#.#.#.#.|.|)");
    vs.push_back("+------------------------+");
    
    int n; cin >> n;
    for(int j = 0; j < 100 && n > 0; j++)
        for(int i = 0; i < (int)vs.size() && n > 0; i++){
            if(j >= vs[i].size()) break;
            if(vs[i][j] == '#')
                vs[i][j] = 'O', n--;
        }
        
    for(string s : vs)
        cout << s << endl;
    
    return 0;
}
