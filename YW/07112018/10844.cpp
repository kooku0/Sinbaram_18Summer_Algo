#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;

	//int result = 0;
	int nArr[101];
	int zeronine[101];
	int i;

	nArr[0] = 0;
	nArr[1] = 1;
	nArr[2] = 2;
	nArr[3] = 3;
	zeronine[0] = 0;
	zeronine[1] = 9;
	zeronine[2] = 17;
	zeronine[3] = 34;
	if (size < 4)
	{
		goto finishphase;
	}
	for (i=4;i<=size;++i)
	{
		nArr[i] = 2 * nArr[i - 1];
		zeronine[i] = (2 * zeronine[i - 1] - nArr[i - 1]) % 1000000000;
	}
	/*9, 1 -> 17, 2 -> 34, 3°³ -> 65, 6°³
		8->9
		1->0
		7,9->8
		0,2->1
	0, 9 -> 1°³
	*/
finishphase:
	printf("%d\n", zeronine[size]);
	return 0;
}