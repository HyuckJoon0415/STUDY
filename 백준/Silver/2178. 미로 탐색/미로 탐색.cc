#include <queue>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Point {
	int x, y, d;
};

int n, m;
int D[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int path(vector<vector<char>> g) {
	vector<vector<bool>> v(n, vector<bool>(m, false));
	queue<Point> q;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == m - 1) return cur.d;

		if (v[cur.x][cur.y]) continue;
		v[cur.x][cur.y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + D[i][0], ny = cur.y + D[i][1];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
			if (g[nx][ny] == '0') continue;
			if (v[nx][ny]) continue;
			q.push({ nx,ny,cur.d + 1 });
		}
	}
}

int main(void) {
	cin >> n >> m;

	vector<vector<char>> g(n, vector<char>(m, 0));
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) g[i][j] = s[j];
	}

	cout << path(g);

	return 0;
}