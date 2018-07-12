#include <iostream>
#include <vector>
#include <algorithm>	
#include <limits.h>
using namespace std;
struct point {
	long long a, b;
};

bool cmp(const point &a, const point &b) {
	if (a.a == b.a) return a.b < b.b;
	else return a.a < b.a;
}
point arr[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Size;
	cin >> Size;
	//vector<vector<int>>arr(Size,vector<int>(2));
	//int arr[100000][2];


	for (int i = 0; i < Size; i++) {
		long long s, e;
		cin >>  s >> e;
		arr[i] = {s,e};
		
	}
	
	sort(arr,arr+Size,cmp);

	int k=0;
	long long befEnd = 0;
	int beforIdx = -1;

	while (true) {
		
		int flag = 0;
		long long tmpStart = 0;
		long long tmpEnd = LLONG_MAX;
		
		for (int i = beforIdx+1; i < Size; i++) {
			//if (tmpEnd == 0)tmpEnd = arr[i].b;
			if (arr[i].a > tmpEnd) {
				break;
			}
			if (befEnd <= arr[i].a && arr[i].b < tmpEnd) {

				tmpStart = arr[i].a;
				tmpEnd = arr[i].b;
				beforIdx = i;
				flag = 1;
			
			}
			
			
		}

		if (flag == 0) {

			cout << k << endl;
			
			return 0;
		}
		befEnd = tmpEnd;

		k++;
		
	}

	


	return 0;
}