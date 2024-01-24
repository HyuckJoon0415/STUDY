#include <iostream>
#include <queue>
using namespace std;

int n, m;

void bfs(vector<vector<int>>& g, vector<bool>& v, int nn) {
	queue<int> q;
	q.push(nn);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (v[cur]) continue;
		v[cur] = true;
		for (int i = 0; i < n; i++) {
			if (g[i][cur] == 1) q.push(i);
		}
	}	
}

int main(void) {
	cin >> n >> m;
	int cnt = 0;
	vector<vector<int>> g(n, vector<int>(n, 0));
	vector<bool> v(n, false);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		cin >> u >> v;
		u--; v--;
		g[u][v] = g[v][u] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!v[i]) { bfs(g, v, i); cnt++; }		
	}
	cout << cnt;
	return 0;
}