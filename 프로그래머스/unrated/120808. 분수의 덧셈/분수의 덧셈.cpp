#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
	int a = lcm(denom1, denom2);
	vector<int> answer;

	numer1 *= (a / denom1);
	numer2 *= (a / denom2);
	numer1 = numer1 + numer2;

	int b = gcd(numer1, a);
	if (b == 1) { answer.emplace_back(numer1); answer.emplace_back(a);}
	else {
		numer1 /= b;
		a /= b;
		answer.emplace_back(numer1);
		answer.emplace_back(a);
	}
	return answer;
}