#include <bits/stdc++.h>
using namespace std;

int mat[105][105];

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	for(int i = 0; i < n; i++)
		cout << sqrt(mat[i][i]) << " ";
	cout << endl;
	return 0;
}
