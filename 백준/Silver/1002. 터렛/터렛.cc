#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int t = 0;
	int x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) { cout << -1 << endl; continue; }
		int d = pow((x1 - x2), 2) + pow((y1 - y2), 2);
		double dd= sqrt(d);
		int rb = r1 > r2 ? r1 : r2;
		int rs = r1 < r2 ? r1 : r2;
		if (rb - rs < dd && dd < rb + rs) cout << 2;
		else if (rb + rs == dd || rb - rs == dd) cout << 1;		
		else cout << 0;
		cout << endl;
	}
	return 0;
}