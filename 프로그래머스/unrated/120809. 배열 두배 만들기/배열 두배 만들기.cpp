#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int a = 0;
    for (auto i : numbers) { i *= 2; numbers[a++] = i; }      
    return numbers;
}