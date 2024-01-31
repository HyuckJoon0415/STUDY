#include <string>
#include <vector>
using namespace std;

void dfs(vector<string> words, string begin, string target, int answer);
int findDiff(string a, string b);
int solution(string begin, string target, vector<string> words);

bool visited[50];
int ans = 51;

void dfs(vector<string> words, string begin, string target, int step) {
	if (step >= ans) {
		return;
	}
	if (begin == target) {
		ans = min(ans, step);
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;
		cnt = findDiff(begin, words[i]);
		if (cnt == 1 && !visited[i]) {
			visited[i] = true;
			dfs(words, words[i], target, step + 1);
			visited[i] = false;
		}
	}
}

int findDiff(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) cnt++;
	}

	return cnt;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	dfs(words, begin, target, 0);
	if (ans == 51) return 0;
	else {
		answer = ans;
		return answer;
	}
}