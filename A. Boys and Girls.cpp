#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    ofstream outfile("output.txt");
    int n, m; file >> n >> m;
    int mini = min(n,m);
    for(int i = 0; i < mini; i++){
        if(n < m)
            outfile << "GB";
        else
            outfile << "BG";
    }
    n -= mini;
    m -= mini;
    for(int i = 0; i < max(n,m); i++)
        outfile << (n > m ? 'B' : 'G');
    outfile << endl;
    return 0;
}
