#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;
    int temp = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (temp == arr[i]) continue;
        answer.emplace_back(arr[i]);
        temp = arr[i];
    }



    return answer;
}