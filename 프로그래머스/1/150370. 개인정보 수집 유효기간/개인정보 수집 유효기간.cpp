#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	/*today안의 문자열을 년,월,일 잘라서 매핑*/
	unordered_map<string, int> todayMap;
	stringstream ss(today);
	string token;
	queue<string> data;
	while (getline(ss, token, '.')) {
		data.push(token);
	}
	todayMap["year"] = stoi(data.front());
	data.pop();
	todayMap["month"] = stoi(data.front());
	data.pop();
	todayMap["date"] = stoi(data.front());
	data.pop();

	/*terms벡터를 매핑*/
	unordered_map<char, int> termMap;
	for (int i = 0; i < terms.size(); i++) {
		string cmd;
		char type = terms[i].front();
		cmd = terms[i].substr(terms[i].find(" "), terms[i].length());
		int n = stoi(cmd);
		
		termMap[type] = n;
	}

	/*privacies 벡터안의 문자열들 중 '.'을 공백으로 바꿔주는 반복문*/
	for (int i = 0; i < privacies.size(); i++) {
		for (int j = 0; j < privacies[i].size(); j++) {
			if(privacies[i][j] == '.') privacies[i][j] = ' ';
		}
	}

	for (int i = 0; i < privacies.size(); i++) {
		stringstream tempSS(privacies[i]);
		int Y, M, D;
		char T=privacies[i].back();	
		while (getline(tempSS, token, ' ')) {
			data.push(token);
		}
		Y = stoi(data.front());
		data.pop();
		M = stoi(data.front());
		data.pop();
		D = stoi(data.front());
		data.pop();
		data.pop();

		/*함정 존재. 약정기간이 13이상일 경우, 약정기간이 12의 배수일 경우*/
		if ((M + termMap[T]) > 12) {
			if ((M + termMap[T]) % 12 == 0) {
				Y += (M + termMap[T]) / 12 - 1;
				M += termMap[T] % 12;
			}
			else {
				Y += (M + termMap[T]) / 12;
				M = (M + termMap[T]) % 12;
			}			
		}
		else M += termMap[T];

		if (todayMap["year"] > Y) {	//날짜를 지난 경우
			answer.push_back(i+1);
			continue;
		}
		else if (todayMap["year"] == Y) {
			if (todayMap["month"] > M) { //날짜를 지난 경우
				answer.push_back(i+1);
				continue;
			}
			else if (todayMap["month"] == M) {
				if (todayMap["date"] >= D) {
					answer.push_back(i+1);
					continue;
				}
				else {
					continue;
				}
			}
			else {	//오늘 달이 약정기간 달 보다 작은 경우
				continue;
			}
		}
		else {	//오늘 연도가 약정기간 연도보다 작은 경우
			continue;
		}
	}
	return answer;
}