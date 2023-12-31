#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1-빵, 2-야채, 3-고기

int solution(vector<int> ingredient) {    
    stack<int> mys;
    int answer = 0;
    for (int i = 0; i < ingredient.size(); i++) {
        mys.push(ingredient[i]);
        if (mys.size() >= 4) {
            int arr[4] = { 0, };
            for (int j = 0; j < 4; j++) {
                arr[j] = mys.top();
                mys.pop();
            }
            if (arr[0] == 1 && arr[1] == 3 && arr[2] == 2 && arr[3] == 1) {
                answer++;
            }
            else {
                for (int j = 3; j >= 0; j--) {
                    mys.push(arr[j]);
                }
            }
        }
    }
    return answer;
}