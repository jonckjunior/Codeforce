#include <bits/stdc++.h>
using namespace std;

struct Node{
	int vida, dano, bonus;
	Node(int _vida, int _dano, int _bonus){
		vida = _vida;
		dano = _dano;
		bonus = _bonus;
	}
	bool operator <(const Node& other) const{
		double t1 = (double)vida/dano, t2 = (double)vida/(dano+bonus);
		double w1 = (double)other.vida/other.dano, w2 = (double)other.vida/(other.dano+other.bonus);
		return t1-t2 > w1-w2;
	}
};


int main(){
	int n, k, v;
	while(cin >> n >> k >> v){
		multiset<Node> s;
		double res = 0;
		for(int i = 0; i < n; i++){
			int x, d; cin >> x >> d;
			res += (double)x/v;
			s.insert(Node(x, v, d));
		}
		for(int i = 0; i < min(n,k); i++){
			Node lst = *(s.begin());
			s.erase(s.begin());
			double t1 = (double)lst.vida/lst.dano, t2 = (double)lst.vida/(lst.dano+lst.bonus);
			res -= t1-t2;
		}
		printf("%.4f\n", res);
	}
	return 0;
}
