#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> map1;
    for (int i = 0; i < players.size(); i++) {
        map1[players[i]] = i;
    }
    for (int i = 0; i < callings.size(); i++) {
        int tempIdx = map1[callings[i]];
        swap(players[tempIdx], players[tempIdx-1]);
        map1[callings[i]]--;
        map1[players[tempIdx]]++;
    }
    answer = players;
    return answer;
}