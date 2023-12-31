#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
	string leftStart;	
	string revLeftStart;

	for (int i = 1; i < food.size(); i++) {
		if (food[i]<2) continue;	//Check even		
		for (int j = 0; j < food[i] / 2; j++) {
			leftStart += to_string(i);
		}
	}
	revLeftStart = leftStart;
	reverse(revLeftStart.begin(), revLeftStart.end());
	leftStart += "0";
	leftStart += revLeftStart;
	return leftStart;
}