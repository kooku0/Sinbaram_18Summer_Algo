#include <iostream>
#include <string>

int main(void)
{
    int numStep;
    std::cin >> numStep;

    const unsigned long long int remainder = 1000000000;

    unsigned long long int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    unsigned long long int arr_temp[10];

    for (int i = 1; i < numStep; ++i) {
        arr_temp[0] = arr[1];

        for (int i = 1; i < 9; ++i)
            arr_temp[i] = arr[i-1] + arr[i+1];
        
        arr_temp[9] = arr[8];

        for (int i = 0; i < 10; ++i) 
            arr[i] = arr_temp[i];
    }

    unsigned long long int count = 0;
    for (int i = 1; i < 10; ++i)
        count += arr[i];

    std::cout << count % remainder << std::endl;
    return 0;
}