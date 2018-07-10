#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<int, int> checkingOver(int* arr, int left, int right);
void quickSearch(int *arr, int left, int right);

int globalWide = -1;
int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int numRect = -1;

    while(cin >> numRect)
    {
        if (numRect == 0)
            break;
            
        vector<int> histogram(numRect);

        for (int i = 0; i < numRect; ++i)
            cin >> histogram[i];
        
        globalWide = -1;
        quickSearch(&histogram[0], 0, numRect);

        cout << globalWide << endl;
    }
    return 0;
}


pair<int, int> checkingOver(int* arr, int left, int right, int* pivotIdx) //주어진 히스토그램 구간에서 모든 left, right 구간을 포함하는 직사각형 넓이를 구함
{
    int minHeight = numeric_limits<int>::max();
    int leftMaxHeight = -1, rightMaxHeight = -1;

    for (int i = left; i < right; ++i) {
        if (minHeight > arr[i]) {
            minHeight = arr[i];
            leftMaxHeight = rightMaxHeight;
            rightMaxHeight = minHeight;
            *pivotIdx = i;
        }
        if (rightMaxHeight < arr[i])
            rightMaxHeight = arr[i];
    }

        const int wide = minHeight * (right - left);

        if (wide > globalWide)
            globalWide = wide;

    return make_pair(leftMaxHeight, rightMaxHeight);
}
void quickSearch(int *arr, int left, int right)
{   
    static int call = 0;
    ++call;
    cout << "Call : " << call << endl;

    if (left < right)
    {
        int pivotIdx;
        const pair<int, int> lrMaxHeight = checkingOver(arr, left, right, &pivotIdx);

        if (right - left == 1) return;

        const int leftMaxWide = lrMaxHeight.first * (pivotIdx - left);
        const int rightMaxWide = lrMaxHeight.second * (right - pivotIdx - 1);        

        if (leftMaxWide > rightMaxWide)
            quickSearch(arr, left, pivotIdx);
        else if (leftMaxWide < rightMaxWide)
            quickSearch(arr, pivotIdx + 1, right);
        else {
            quickSearch(arr, left, pivotIdx);
            quickSearch(arr, pivotIdx + 1, right);
        }
    }
    else
    {
        return;
    }
}