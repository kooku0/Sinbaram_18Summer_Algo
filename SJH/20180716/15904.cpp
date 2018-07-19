#include <iostream>

using namespace std;
int main(void)
{
    int idx = 0;
    char ucpc[] = "UCPC";
    char temp;

    while ((temp = getchar()) != EOF && idx != 4) 
    {
        if (temp == ucpc[idx]) {
            ++idx;
        }
    }

    if (idx == 4) {
        cout << "I love UCPC" << endl;
    }
    else {
        cout << "I hate UCPC" << endl;
    }

    return 0;
}