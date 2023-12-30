#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string solution(string code) {
	int mode = 1; 
	string ret;
	for (int i = 0; i < code.length(); i++) {
		if (code[i] == '1') {
			mode *= -1;
			continue;
		}
		if (mode == 1) {
			if (i % 2 == 0) {
				ret += code[i];				
			}
		}
		else {
			if (i % 2 != 0) {
				ret += code[i];
			}
		}
	}
	return ret.empty() ? "EMPTY" : ret;
}

int main(void) {
	string code;	
	cin >> code;
	code = solution(code);
	cout << code;
	return 0;
}