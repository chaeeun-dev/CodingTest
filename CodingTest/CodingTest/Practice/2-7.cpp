#include <iostream>
#include <algorithm>	// std::max({a, b, c})

int main(void)
{
	int A, B, C;
	std::cin >> A >> B >> C;

	int reward;

	if ((A == B) && (B == C))
		reward = 10000 + A * 1000;
	else if (A == B)
		reward = 1000 + A * 100;
	else if (B == C)
		reward = 1000 + B * 100;
	else if (A == C)
		reward = 1000 + A * 100;
	else 
	{
		/*int maxVal = std::max(A, B);
		maxVal = std::max(maxVal, C);*/
		int maxVal = std::max({ A,B,C });

		reward = maxVal * 100;
	}

	std::cout << reward << std::endl;

	return 0;
}