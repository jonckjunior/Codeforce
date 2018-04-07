#include <bits/stdc++.h>

using namespace std;

#define TOL 1e-9

#define LE(x, y) (x - y < TOL)
#define GE(x, y) LE(y, x)
#define EQ(x, y) (LE(x, y) && GE(x, y))

typedef pair<double, double> dd;

bool inside(dd b, dd a) {
    return GE(b.first, a.first) && LE(b.second, a.second);
}

bool intersect(dd a, dd b, dd& c) {
    if (GE(a.second, b.first) && GE(b.second, a.second)) {
        c = {b.first, a.second};
        return true;
    }
    if (GE(b.second, a.first) && GE(a.second, b.second)) {
        c = {a.first, b.second};
        return true;
    }
    return false;
}

int main(){
    cout.sync_with_stdio(false); cin.tie(NULL);
    cout.setf(ios_base::fixed); cout.precision(9);
    int n; cin >> n;
    vector<int> v, p;
    for (int i = 0; i < n; ++i){
        int x; cin >> x; v.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; p.push_back(x);
    }
    double left = 0, right = 1e9 + 7;
    for (int i = 0; i < 100; ++i) {
        double m = (left + right) / 2.0;
        //cout << m<< endl << endl;
        vector<dd> k;
        for (int i = 0; i < n; ++i) {
            k.push_back({v[i] - m * p[i],  v[i] + m * p[i]});
        }
        bool flag = true;
        while (k.size() > 1) {
            dd a = k.back(); k.pop_back();
            dd b = k.back(); k.pop_back();
            dd c;
            //cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
            if (inside(a, b)) k.push_back(a);
            else if (inside(b, a)) k.push_back(b);
            else if (intersect(a, b, c) || intersect(b, a, c))
                        k.push_back(c);
            else { flag = false; break; }
        }
        if (!flag) left = m;
        else right = m;
    }
    cout << left << endl;
    return 0;
}
