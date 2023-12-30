#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int D[4][2] = {
	{-1,0}, //up
	{1,0},	//down
	{0,-1},	//left
	{0,1}	//right
};
int N, M;


int bfs(vector<string> maze,vector<vector<int>> dist) {
	vector<vector<bool>> visited(N, vector<bool>(M, false));	
	queue<pair<int,int>> myq;

	myq.emplace(0, 0);
	dist[0][0] = 1;

	while (!myq.empty()) {
		pair<int, int> cur = myq.front();
		myq.pop();

		if (cur.first == N - 1 && cur.second == M - 1) {
			return dist[cur.first][cur.second];
		}

		for (int i = 0; i < 4; i++) {
			int cr = cur.first + D[i][0];
			int cc = cur.second + D[i][1];
			if (cr >= N || cc >= M || cr < 0 || cc < 0) continue;
			if (visited[cr][cc]) continue;
			if (maze[cr][cc] == '0') continue;
			visited[cr][cc] = true;
			dist[cr][cc] = dist[cur.first][cur.second] + 1;
			myq.emplace(cr, cc);
		}
	}

}

int main(void) {	
	cin >> N >> M;
	
	vector<string> maze;
	vector<vector<int>> dist(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		maze.emplace_back(temp);
	}

	cout << bfs(maze,dist);
	return 0;
}