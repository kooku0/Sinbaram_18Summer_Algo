#include <iostream>
#include <vector>

using namespace std;

void quickCheck(int left, int top, int size);

vector<vector<int>> paper; 
int countFirst;
int countSecond;
int countThird;


int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int width;
    cin >> width;
    paper = vector<vector<int>>(width, vector<int>(width));

    for (int r = 0; r < width; ++r)
        for (int c = 0; c < width; ++c)
            cin >> paper[r][c];

    quickCheck(0, 0, width);

    cout << countFirst << endl;
    cout << countSecond << endl;
    cout << countThird << endl;

    return 0;
}



bool checkingOver(int left, int top, int size)
{
    int temp = paper[left][top];

    for (int r = left; r < left + size; ++r)
        for (int c = top; c < top + size; ++c)
            if (temp != paper[r][c])
                return false;
    

    switch(temp)
    {
        case -1 :
            ++ countFirst;
            break;
        case 0 :
            ++ countSecond;
            break;
        case 1 :
            ++ countThird;
            break;
    }

    return true;
}

void quickCheck(int left, int top, int size)
{
    if (size != 0)
    {
        bool result = checkingOver(left, top, size);
        
        int partitionSize = size / 3;

        if (!result)
        {
            quickCheck(left, top, partitionSize);
            quickCheck(left + partitionSize, top, partitionSize);
            quickCheck(left + 2 * partitionSize, top, partitionSize);
            quickCheck(left, top + partitionSize, partitionSize);
            quickCheck(left + partitionSize, top + partitionSize, partitionSize);
            quickCheck(left + 2 * partitionSize, top + partitionSize, partitionSize);
            quickCheck(left, top + 2 * partitionSize, partitionSize);
            quickCheck(left + partitionSize, top + 2 * partitionSize, partitionSize);
            quickCheck(left + 2 * partitionSize, top + 2 * partitionSize, partitionSize);
        }
        
    }
}