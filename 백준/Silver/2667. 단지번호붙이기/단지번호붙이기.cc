#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int D[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

struct Point {
	int x, y;
};

bool visited[26][26] = { false, };
int cnt;

int bfs(vector<string> str_g, int i, int j, int n) {
	queue<Point> myq;
	int dist = 0;
	myq.push({ i,j });

	while (!myq.empty()) {
		Point cur = myq.front();

		myq.pop();

		if (visited[cur.x][cur.y]) continue;
		dist++;
		visited[cur.x][cur.y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + D[i][0], ny = cur.y + D[i][1];
			if (visited[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= n || str_g[nx][ny] == '0') continue;
			myq.push({ nx,ny });
		}
	}
	return dist;
}


int main(void) {
	int n = 0;
	cin >> n;
	vector<string> str_g;
	vector<int> result;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		str_g.push_back(str);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str_g[i][j] == '1' && !visited[i][j]) {
				cnt++;
				result.emplace_back(bfs(str_g, i, j, n));
			}

		}
	}
	result.insert(result.begin(), cnt);
	sort(result.begin()+1, result.end());
	for (auto i : result) {
		cout << i << endl;
	}

	return 0;
}
