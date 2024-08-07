#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
	visited[node] = true;
	cout << node << ' ';

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) {
			dfs(graph, visited, next);
		}
	}
}

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
		
	}
}

int main() {
	int N = 0, M = 0, V = 0;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);
	vector<bool> visited(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u = 0, v = 0;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(graph, visited, V);
	fill(visited.begin(), visited.end(), false);
	cout << endl;
	bfs(graph, visited, V);

	return 0;
}