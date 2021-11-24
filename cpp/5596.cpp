#include <iostream>

int sum(int(&scores)[4]) {
	int n;
	for (int i = 0; i < 4; i++)
		n += scores[i];
	return n;
}

int main() {
	int s1[4];
	int s2[4];

	int sum1, sum2;

	std::cin >> s1[0] >> s1[1] >> s1[2] >> s1[3];
	std::cin >> s2[0] >> s2[1] >> s2[2] >> s2[3];
	sum1 = sum(s1);
	sum2 = sum(s2);

	std::cout << (sum1 < sum2 ? sum2 : sum1);
}