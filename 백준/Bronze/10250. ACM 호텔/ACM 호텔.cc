#include <iostream>

using namespace std;

int main(void) {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int H = 0, W = 0, N = 0;
		int result = 0;
		cin >> H >> W >> N;
		if (N % H == 0) {
			result = H * 100;
			result += N / H;
			cout << result << '\n';
			continue;
		}
		result = (N % H) * 100;
		result += (N / H) + 1;
		cout << result << '\n';
	}
	return 0;
}