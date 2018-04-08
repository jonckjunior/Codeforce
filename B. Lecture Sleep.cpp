#include <bits/stdc++.h>
using namespace std;

int v[100005], t[100005];

int main(){
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> v[i];
    for(int i = 1; i <= n; i++)
    	cin >> t[i];

    int sum = 0, res = 0;

    for(int i = 1; i <= n; i++){
    	if(t[i] == 1)
    		sum += v[i];
    }

    deque<int> dq;
    for(int i = 1; i <= n; i++){
    	dq.push_back(i);
    	if(t[i] == 0)
    		sum += v[i];
    	while(dq.back()-dq.front() >= k){
    		if(t[dq.front()] == 0)
    			sum -= v[dq.front()];
    		dq.pop_front();
    	}
    	res = max(res, sum);
    }

    cout << res << endl;
    return 0;
}
