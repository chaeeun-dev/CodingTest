#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
	std::string A, B;
	std::cin >> A >> B;

	std::reverse(A.begin(), A.end());
	std::reverse(B.begin(), B.end());

	int a = stoi(A);
	int b = stoi(B);
	
	std::cout << std::max(a, b);

	return 0;
}