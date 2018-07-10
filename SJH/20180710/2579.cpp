#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int stepNum;
    cin >> stepNum;

    vector<int> step(stepNum); 
    vector<int> storage(stepNum + 1);

    for (int i = 0; i < stepNum; ++i)
        cin >> step[i];

    if (stepNum > 3)
    {
        storage[0] = 0;
        storage[1] = step[0];
        storage[2] = step[0] + step[1];   

        for (int i = 2; i < stepNum; ++i)
        {
            int temp1 = storage[i - 1] + step[i];
            int temp2 = step[i] + step[i-1] + storage[i - 2];

            if (temp1 < temp2)
                storage[i + 1] = temp2;
            else
                storage[i + 1] = temp1;
        }
    }

    cout << storage[stepNum] << endl;

    return 0;
}