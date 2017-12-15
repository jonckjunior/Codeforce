#include <bits/stdc++.h>

using namespace std;

int main() {
	int x,y;
	int v[10][10];
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 5; j++){
			scanf("%d",&v[i][j]);
			if(v[i][j])
				x = i, y = j;
		}
	cout << abs(x-3) + abs(y-3) << endl;
	return 0;
}