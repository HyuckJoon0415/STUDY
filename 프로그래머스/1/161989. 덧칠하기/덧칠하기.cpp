#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<int> section) {
	/*n과 m의 값이 같으면 무조건 1이 답*/
	if (n == m) return 1;
	/*롤러(m)의 길이가 1이면 섹션의 개수가 답*/
	if (m == 1) return section.size();

	int answer = 0;

	/*시작 노드에서 롤러의 길이만큼 칠함. 마지막 노드==endNode*/
	int endNode = section[0] + m - 1;
	answer++;	//칠한 횟수 증가
	for (int i = 0; i < section.size(); i++) {
		if (endNode >= section[i]) continue;
		else {
			endNode = section[i] + m - 1;
			answer++;
		}
	}

	return answer;	
}