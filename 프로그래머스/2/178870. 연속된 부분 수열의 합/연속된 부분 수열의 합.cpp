#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	int s = 0, e = 0;
	int sum = sequence[s];
	vector<int> answer;
	int minCnt = sequence.size(), cnt = 0;

	while (s<sequence.size()) {
		if (sum == k) {			
			cnt = e - s;
			if (minCnt > cnt && cnt>=0) {
				minCnt = cnt;
				answer.clear();
				answer.push_back(s);
				answer.push_back(e);
			}			
			sum -= sequence[s++];
		}
		else if (sum < k) {
			if (e == sequence.size() - 1) break;
			if (e == s) {				
				sum += sequence[++e];
			}			
			else {
				sum += sequence[++e];
			}
		}
		else if (sum > k) {
			if (e == s) {
				if (s == sequence.size() - 1) break;
				sum += sequence[++e];
			}
			else {
				sum -= sequence[s++];				
			}
		}
	}
	return answer;
}