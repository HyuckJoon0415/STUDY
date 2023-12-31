#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int num1 = 0, num2 = 0;

    for (int i = 0; i < goal.size(); i++) {
        if (goal[i] == cards1[num1]) num1++;
        else if (goal[i] == cards2[num2]) num2++;
        else return "No";
    }

    return answer;
}