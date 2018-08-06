#include <iostream>
#include <vector>

using namespace std;

/*
template <int X, int Y>
struct GCD
{
	static const int value = GCD<Y, X%Y>::value;
};

template <int X>
struct GCD<X, 0>
{
	static const int value = X;
};
*/

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> p(N + 1, 1);

    int count = 0;
    int P = 2;

    bool EXIT = true;
    while (EXIT)
    {
        int num = N / P;

        for (int i = 1; i <= num; ++i)
        {
            if (p[i * P] == 1) 
            {
                p[i * P] = 0;
                ++ count;

                if (count == K)
                {
                    std::cout << P * i << '\n';
                    EXIT = false;
                    break;
                }
            }
        }

        ++ P;
    }

    return 0;
}