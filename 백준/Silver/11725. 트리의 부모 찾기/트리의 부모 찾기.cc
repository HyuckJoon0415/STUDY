#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int N = 0;
	cin >> N;

	vector<vector<int>> graph(N + 1);
	vector<int> parent(N + 1, 0);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	parent[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (parent[next]) continue;

			q.push(next);
			parent[next] = cur;
				
		}
	}

	for (int i = 2; i < N + 1; i++) {
		cout << parent[i] << "\n";
	}


	return 0;
}