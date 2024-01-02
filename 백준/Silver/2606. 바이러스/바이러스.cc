#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int n, m;

void aaa(vector<vector<int>> g) {
	int sum = 0;
	vector<bool> v(n, false);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (v[cur]) continue;
		v[cur] = true;
		sum++;
		for (int i = 0; i < n; i++) {
			if (!v[i] && g[cur][i] == 1) {
				q.push(i);
			}
		}
	}
	cout << --sum;
}

int main(void) {
	cin >> n >> m;

	vector<vector<int>> g(n, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = 1;
	}

	aaa(g);
	return 0;
}