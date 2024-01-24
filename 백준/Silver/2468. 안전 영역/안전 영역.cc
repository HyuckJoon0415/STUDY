#include <iostream>
#include <queue>
using namespace std;

int n, cnt;
int D[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};


void bfs2(vector<vector<bool>>& v, vector<vector<int>> g, int x, int y, int maxN) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		if (v[cur.first][cur.second]) continue;
		v[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + D[i][0], ny = cur.second + D[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || g[nx][ny] <= maxN || v[nx][ny]) continue;
			q.push(make_pair(nx, ny));
		}
	}
}

void bfs(vector<vector<int>> g, int maxN) {
	int safeCnt = 0;
	vector<vector<bool>> v(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v[i][j] && g[i][j]>maxN) { bfs2(v, g, i, j, maxN); safeCnt++; }
		}
	}
	if (cnt < safeCnt) cnt = safeCnt;
}

int main(void) {
	int maxN = 0;;

	cin >> n;

	vector<vector<int>> g(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			if (maxN < g[i][j]) maxN = g[i][j];
		}
	}
	for (int i = 0; i < maxN; i++) {
		bfs(g, i);
	}
	cout << cnt;
	return 0;
}