#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int Lcol = 99, Rcol = 0, Trow=99, Brow=0;
    for (int i = 0; i < wallpaper.size(); i++) {        
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                Lcol = Lcol > j ? j : Lcol;
                Rcol = Rcol < j ? j : Rcol;
                Trow = Trow > i ? i : Trow;
                Brow = Brow < i ? i : Brow;
            }
        }
    }
    answer.emplace_back(Trow);
    answer.emplace_back(Lcol);
    answer.emplace_back(Brow+1);
    answer.emplace_back(Rcol+1);

    return answer;
}