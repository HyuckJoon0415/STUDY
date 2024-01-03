#include<vector>
#include <queue>
using namespace std;

int D[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};

struct Point {
	int x, y, d;
};

int solution(vector<vector<int> > maps)
{
	int n = maps.size(), m = maps[0].size();	
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	queue<Point> q;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		if (visited[cur.x][cur.y]) continue;
		if (cur.x == n - 1 && cur.y == m - 1) return cur.d;
		
		visited[cur.x][cur.y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + D[i][0], ny = cur.y + D[i][1];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
			if (visited[nx][ny]) continue;
			if (maps[nx][ny] == 0) continue;
			q.push({ nx,ny,cur.d + 1 });
		}
	}	
	return -1;
}