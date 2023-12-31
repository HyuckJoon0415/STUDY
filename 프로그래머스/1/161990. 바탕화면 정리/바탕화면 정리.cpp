#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;	
	int eRow = 0, eCol = 0;
	int sRow = 0, sCol = 0;
	bool startNode = false;

	for (int i = 0; i < wallpaper.size(); i++) {
		for (int j = 0; j < wallpaper[i].size(); j++) {
			if (wallpaper[i][j] == '#') {
				if (!startNode) {
					sRow = i, sCol = j;
					startNode = true;
				}
				if (sRow > i) sRow = i;
				if (sCol > j) sCol = j;
				if (eCol < j) eCol = j;
				if (eRow < i) eRow = i;
			}
		}
	}	
	answer.push_back(sRow);
	answer.push_back(sCol);
	answer.push_back(eRow+1);
	answer.push_back(eCol+1);
	
	return answer;
}