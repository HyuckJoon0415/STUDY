#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int D[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};
int n, m, zc;

struct Point {
	int x, y, d;
};

void bfs(vector<vector<bool>> v, vector<vector<int>> g, queue<Point> q) {
	queue<Point> aq;
	int num = q.size();
	for (int i = 0; i < num; i++) {
		aq.push(q.front());
		q.pop();
	}
	bool isTrue = true;
	while (!aq.empty()) {
		Point cur = aq.front();
		aq.pop();

		if (v[cur.x][cur.y]) continue;
		if (g[cur.x][cur.y] == 0) {
			zc--;
			if (zc == 0) { cout << cur.d; return; }
		}		
		
		v[cur.x][cur.y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + D[i][0], ny = cur.y + D[i][1];
			if (nx< 0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
			if (v[nx][ny]) continue;
			if (g[nx][ny] == -1) continue;
			aq.push({ nx, ny, cur.d + 1 });
		}
	}	
	cout << -1;
}

int main(void) {
	cin >> m >> n;
	vector<vector<bool>> v(n, vector<bool>(m, false));
	vector<vector<int>> g(n, vector<int>(m, 0));
	queue<Point> q;
	zc = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 1) {
				q.push({ i,j,0 });
			}
			if (g[i][j] == 0) zc++;
		}
	}
	if (zc == 0) {
		cout << 0;
		return 0;
	}
	bfs(v, g, q);
	return 0;
}
