// 다음 순열 (TUKorea, 구현) 
// http://210.93.60.51/problem/0057

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    while (K--)
    {
        vector<int> v(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> v[i];
        }

        // 다음 순열이 존재하면
        if (next_permutation(v.begin(), v.end()))
        {
            for (int x : v)
            {
                cout << x << " ";
            }
        }
        else
        {
            // 마지막 순열이면 이전 순열 출력
            prev_permutation(v.begin(), v.end());

            for (int x : v)
            {
                cout << x << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}