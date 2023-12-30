#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    n = n - m;  //same => '0' , n>m => '+' , n<m => '-'
    if (n < 0) {
        if (ineq == "<") answer = 1;
    }
    else if (n > 0) {
        if (ineq == ">") answer = 1;
    }
    else {
        if (eq == "=") answer = 1;
    }
    return answer;
}