#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int n, m;

void dfs(vector<vector<int>> graph, vector<bool> visited, int v) {
	stack<int> s;
	s.push(v);

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		if (visited[cur]) continue;

		visited[cur] = true;
		cout << cur + 1 << ' ';
		for (int i = n - 1; i >= 0; i--) {
			if (!visited[i] && graph[cur][i] == 1) {
				s.push(i);
			}
		}
	}

}

void bfs(vector<vector<int>> graph, vector<bool> visited, int v) {
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visited[cur]) continue;

		visited[cur] = true;
		cout << cur + 1 << ' ';
		for (int i = 0; i < n; i++) {
			if (!visited[i] && graph[cur][i] == 1) {
				q.push(i);
			}
		}
	}
}

int main(void) {
	int v = 0;
	cin >> n >> m >> v;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<bool> visited(n, false);

	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		a--; b--;
		graph[a][b] = graph[b][a] = 1;
	}
	dfs(graph, visited, v - 1);
	cout << endl;
	bfs(graph, visited, v - 1);

	return 0;
}