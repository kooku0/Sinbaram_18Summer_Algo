#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int numCard, numComb;
    cin >> numCard >> numComb;

    vector<long long unsigned int> cards(numCard);

    for (int i = 0; i < numCard; ++i)
        cin >> cards[i];

    long long unsigned int sum = 0;

    for (int i = 0; i < numComb; ++i) 
    {
        sort(cards.begin(), cards.end());
        sum = cards[0] + cards[1];
        cards[0] = sum;
        cards[1] = sum;
    }

    sum = 0;
    for (int i = 0; i < numCard; ++i)
        sum += cards[i];
    
    cout << sum << endl;

    return 0;
}