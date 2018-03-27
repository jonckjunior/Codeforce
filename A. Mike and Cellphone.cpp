#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii adam;
int m[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

bool dfs(int a, int b, int daVez) {
    if (daVez >= adam.size()) return true;
    int x = a + adam[daVez].first, y = b + adam[daVez].second;
    if (x >= 0 && y >= 0 && x < 4 && y < 3 && m[x][y] != -1)
        return dfs(x, y, daVez + 1);
    return false;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;

    ii weiss[11][11];
    for (int i = 0; i < 4; ++i) {
        for (int a = 0; a < 3; ++a) {
            if (m[i][a] == -1) continue;
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 3; ++k) {
                    if (m[j][k] == -1) continue;
                    weiss[m[i][a]][m[j][k]] = ii(j - i, k - a);
                }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        adam.push_back(weiss[s[i] - '0'][s[i + 1] - '0']);
    }
    int k = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if (m[i][j] != -1 && dfs(i, j, 0)){
                    ++k;
            }
        }
    }
    if (k <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
