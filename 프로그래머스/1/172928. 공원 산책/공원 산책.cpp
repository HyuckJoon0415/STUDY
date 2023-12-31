#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	int row = park.size() - 1;
	int col = park[0].size() - 1;
	int sr = 0, sc = 0;
	for (int i = 0; i < park.size(); i++) {
		for (int j = 0; j < park[i].size(); j++) {
			if (park[i][j] == 'S') { sr = i; sc = j; }
		}
	}

	for (int i = 0; i < routes.size(); i++) {
		int Idx = routes[i][2] - 48;
		for (int j = 0; j < Idx; j++) {
			if (routes[i][0] == 'E') {
				sc++;
				if (park[sr][sc] == 'X' || sc > col) { sc -= (j + 1);  break; }
			}
			else if (routes[i][0] == 'W') {
				sc--;
				if (park[sr][sc] == 'X' || sc < 0) { sc += (j + 1); break; }
			}
			else if (routes[i][0] == 'S') {
				sr++;
				if (park[sr][sc] == 'X' || sr > row) { sr -= (j + 1); break; }
			}
			else if (routes[i][0] == 'N') {
				sr--;
				if (park[sr][sc] == 'X' || sr < 0) { sr += (j + 1); break; }
			}
		}
	}
	answer.emplace_back(sr);
	answer.emplace_back(sc);
	return answer;
}