#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int n = 0;
	cin >> n;

	string opsStr;
	stack<int> mys;
	bool noFlag = false;
	bool breakFlag = false;
	int myNum = 1;
	while (n--) {
		int num = 0;
		cin >> num;
		if (breakFlag) continue;
		if (myNum <= num) {
			while (myNum <= num) {
				mys.push(myNum++);
				opsStr += "+";
			}
		}
		if (myNum >= num) {
			if (mys.empty()) {
				noFlag = true;
				breakFlag = true;
				continue;
			}
			while (mys.top() != num) {
				mys.pop();
				opsStr += "-";
				if (mys.empty()) {
					noFlag = true;
					breakFlag = true;
				}
				if (breakFlag) break;
			}
			if (breakFlag) continue;
			mys.pop();
			opsStr += "-";
		}


	}
	if (noFlag) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < opsStr.size(); i++) {
		cout << opsStr[i] << "\n";
	}
	return 0;
}