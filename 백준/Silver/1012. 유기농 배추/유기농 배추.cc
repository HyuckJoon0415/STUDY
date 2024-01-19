#include <iostream>
#include <queue>
using namespace std;


int cnt, m, n;
int D[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

void bfs(bool visited[][50], int j, int k, int g[][50]) {
	queue<pair<int, int>> myq;
	myq.push(make_pair(j, k));

	while (!myq.empty()) {
		pair<int, int> cur = myq.front();
		myq.pop();

		if (visited[cur.first][cur.second]) continue;
		visited[cur.first][cur.second] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + D[i][0], ny = cur.second + D[i][1];
			if (visited[nx][ny] || nx < 0 || ny < 0 || g[nx][ny] == 0 || nx >= m || ny >= n) continue;
			myq.push(make_pair(nx, ny));
		}
	}
}

int main(void) {
	int t = 0, k = 0;
	cin >> t;
	
	vector<int> v;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		bool visited[50][50] = { false, };
		int g[50][50] = { 0, };
		cnt = 0;
		for (int j = 0; j < k; j++) {
			int a = 0, b = 0;
			cin >> a >> b;
			g[a][b] = 1;
		}
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (g[j][k] == 1 && !visited[j][k]) {
					cnt++;
					bfs(visited, j, k, g);
				}
				
			}
		}
		v.emplace_back(cnt);
	}
	for (auto i : v) cout << i << endl;
	return 0;
}