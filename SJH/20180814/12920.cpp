#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _item 
{
    int weight;
    int value;
    int number;
} Item;

int main(void)
{
    int numType, maxWeight;
    cin >> numType >> maxWeight;

    vector<Item> itemList(numType);

    for (auto& item : itemList)
        cin >> item.weight >> item.value >> item.number;

    vector<vector<int>> dpTable(numType + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i < numType + 1; ++i)
    {
        for (int j = 1; j < maxWeight + 1; ++j)
        {
            if (j < itemList[i - 1].weight)
                dpTable[i][j] = dpTable[i - 1][j];
            else 
            {
                int num = j / itemList[i - 1].weight;
                num = itemList[i-1].number < num ? itemList[i-1].number : num;

                int maxValue = - 1;
                for (int idx = 0; idx <= num; ++idx)
                {
                    int newValue = itemList[i - 1].value * idx + dpTable[i - 1][j - itemList[i - 1].weight * idx];
                    if (newValue > maxValue)
                        maxValue = newValue;
                }

                dpTable[i][j] = maxValue;
            }
        }
    }

    cout << dpTable[numType][maxWeight] << endl;

    return 0;
}