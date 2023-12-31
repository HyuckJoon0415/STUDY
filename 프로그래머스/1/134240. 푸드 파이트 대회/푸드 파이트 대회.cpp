#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for (int i = 1; i < food.size();i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer += to_string(i);
            temp = answer;
        }
    }
    reverse(temp.begin(), temp.end());
    answer += "0";
    answer += temp;
    return answer;
}