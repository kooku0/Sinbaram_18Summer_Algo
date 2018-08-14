#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _item {
    int weight;
    int value;
} Item;

int main(void)
{
    int numItem, maxWeight;
    cin >> numItem >> maxWeight;

    vector<Item> itemList(numItem);
    vector<vector<int>> storage(numItem + 1, vector<int>(maxWeight + 1, 0));

    for (auto& item : itemList)
        cin >> item.weight >> item.value;

    for (int i = 1; i < numItem + 1; ++i)
    {
        for (int j = 1; j <= maxWeight; ++j)
        {
            if (j < itemList[i - 1].weight)
            {
                storage[i][j] = storage[i - 1][j];
            }
            else 
            {
                storage[i][j] = max(storage[i - 1][j], itemList[i - 1].value + storage[i - 1][j - itemList[i - 1].weight]);
            }
        }
    }

    cout << storage[numItem][maxWeight] << endl;

    return 0;
}