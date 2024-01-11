#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n = 0, k = 0;
	cin >> n >> k;
	
	queue<pair<int,int>> q;
	q.push(make_pair(n, 0));

	bool v[100001] = { false, };

	while (!q.empty()) {
		int cur = q.front().first, time=q.front().second;
		if (cur == k) { cout << time; break; }
		q.pop();
		if (0 > cur || cur > 100000) continue;
		
		if (!v[cur]) {
			v[cur] = true;

			q.push(make_pair(cur + 1, time + 1));
			q.push(make_pair(cur - 1, time + 1));
			q.push(make_pair(cur * 2, time + 1));
		}		
	}

	return 0;
}