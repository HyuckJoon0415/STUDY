#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main(void) {
	string exp;
	cin >> exp;

	string answerStr;
	stack<char> mys;
	unordered_map<char, int> myUmap;
	myUmap['*'] = 5;
	myUmap['/'] = 5;
	myUmap['('] = 0;
	myUmap['+'] = 1;
	myUmap['-'] = 1;

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] >= 'A' && exp[i] <= 'Z') {
			answerStr += exp[i];
		}
		else {
			/*1.스택이 빈 경우*/
			/*2.스택에 '+', '-' 가 들어있는 경우*/
			/*2-1. 여는 괄호가 오는 경우*/
			/*3.스택에 '*', '/' 가 들어있는 경우*/

			if (mys.empty()) {	//case 1		
				mys.push(exp[i]);
				continue;
			}
			if (myUmap[mys.top()] >= myUmap[exp[i]] && exp[i] != '(') { //case 3					
				if (exp[i] == ')') {
					while (mys.top() != '(') {
						answerStr += mys.top();
						mys.pop();
					}
					mys.pop();
					continue;
				}
				answerStr += mys.top();
				mys.pop();
				i--;
			} //case 2
			else {
				mys.push(exp[i]);
			}
		}
	}
	/*스택에 남아있는 값들 처리*/
	while (!mys.empty()) {
		/*남아있는 값이 괄호인 경우*/
		if (mys.top() == '(' || mys.top() == ')') {
			mys.pop();
			continue;
		}
		answerStr += mys.top();
		mys.pop();
	}
	cout << answerStr;
	return 0;
}