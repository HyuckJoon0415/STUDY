#include <string>
#include <vector>
#include <iostream>
using namespace std;


bool visited[201];

void dfs(vector<vector<int>> computers, int cur, int n) {
	visited[cur] = true;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && computers[i][cur]) {			
			dfs(computers, i, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	
	
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {			
			dfs(computers, i, n);
			answer++;
		}
		
	}	
	return answer;
}