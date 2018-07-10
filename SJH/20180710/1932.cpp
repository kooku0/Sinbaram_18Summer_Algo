#include <iostream>
#include <vector>

using namespace std;

int length;
int triangle[500][500];
int storage[501];

int main(void)
{
    cin >> length;

    for (int i = 0; i < length; ++i)
    {
        vector<int> tempStorage(i + 2);

        for (int j = 0; j < i + 1; ++j) {
            cin >> triangle[i][j];

            const int leftLength = triangle[i][j] + storage[j];
            const int rightLength = triangle[i][j] + storage[j + 1];

            if (leftLength < rightLength)
                tempStorage[j + 1] = rightLength;
            else
                tempStorage[j + 1] = leftLength;
        }

        for (int k = 0; k < i + 2; ++k)
            storage[k] = tempStorage[k];
    }

    int maxHeight = -1;
    for (int i = 1; i < length + 1; ++i)
        if (maxHeight < storage[i])
            maxHeight = storage[i];
    
    cout << maxHeight << endl;

    return 0;
}

