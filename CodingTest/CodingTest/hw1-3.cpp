#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N;
		string init, dest;
		cin >> N >> init >> dest;

		int BCount = 0, WCount = 0;
		for (int j = 0; j < init.length(); ++j)
		{
			if (init[j] != dest[j])
				if (init[j] == 'B')
					BCount++;
				else if (init[j] == 'W')
					WCount++;
		}
		
		int result = 0;

		int exchangeCount = min(BCount, WCount);
		int changeCount = max(BCount, WCount) - exchangeCount;
		result = exchangeCount + changeCount;

		cout << result << endl;
	}

	return 0;
}