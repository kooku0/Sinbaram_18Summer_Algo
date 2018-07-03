#include <iostream>
#include <string>

using namespace std;

int main()
{
	// A, B, C는 모두 3자리수

	/*
	int A;
	int B;
	int C;

	cin >> A;
	cin >> B;
	cin >> C;

	*/
	int D;
	cin >> D;
	// D = A * B * C;
		
	for (int i = 0; i < 10; i++)
	{
		//각 자릿수에 i가 몇개있는지 찾아야 됨
		int count = 0;
		while (D != 0)
			if (D % 10 == i)
				count++;
			D = D / 10;
		cout << count << "\n";
	}

	return 0;
	

}

/*
// 1152번 문제
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);
	cout << sentence;

	return 0;
}
*/

/*
#include <iostream>

using namespace std;

int F(int a)
{
	if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	else
		return F(a - 1) + F(a - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << F(n) << endl;
	return 0;
	
}
*/

/*
#include <iostream>

using namespace std;

int NumberofZero(int a)
{
	if (a == 0)
		return 1;
	else if (a == 1)
		return 0;
	else
		return NumberofZero(a - 1) + NumberofZero(a - 2);
}

int NumberofOne(int b)
{
	if (b == 0)
		return 0;
	else if (b == 1)
		return 1;
	else
		return NumberofOne(b - 1) + NumberofOne(b - 2);
}


int main()
{
	cout << "테스트할 케이스 수 T를 입력하시오" << endl;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cout << "40이하의 자연수 N을 입력하시오" << endl;
		int n;
		cin >> n;
		int* arr = new int[T];
		arrZero[i] = ;
		arrOne[i] = NumberofZero(n);
		cout << NumberofZero(n) << " " << NumberofOne(n) << endl;
	}

	return 0;
}
*/

/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size;
	cin >> size;
	int arr[40][2];
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	int currMax = 2;
	vector<int> v;
	for (int i = 0; i < size; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (currMax<tmp) {
			for (int j = currMax; j <= tmp; j++) {
				arr[j][0] = arr[j - 1][0] + arr[j - 2][0];
				arr[j][1] = arr[j - 1][1] + arr[j - 2][1];
			}
			currMax = tmp;

		}

	}
	for (int i = 0; i < size; i++) {
		cout << arr[v[i]][0] << " " << arr[v[i]][1] << endl;
	}

	return 0;
}
*/