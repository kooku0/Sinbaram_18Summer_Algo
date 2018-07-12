#include <iostream>
#include <limits>

using uint = unsigned int ;

void checkingOver(uint source, uint count);

uint minCount;

int main(void)
{
    uint number;
    std::cin >> number;

    minCount = std::numeric_limits<uint>::max();
    checkingOver(number, 0);

    std::cout << minCount << std::endl;

    return 0;
}

void checkingOver(uint source, uint count)
{
    if (source == 1 && minCount > count) {
        minCount = count;
        return;
    }
    
    if (count > minCount)
        return;
        
    if (source % 3 == 0)
        checkingOver(source / 3, count + 1);
    if (source % 2 == 0)
        checkingOver(source / 2, count + 1);
    
    checkingOver(source - 1, count + 1);
}