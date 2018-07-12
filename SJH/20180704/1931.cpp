#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _schedule {
	int start, end;
} schedule;

bool comp2(const schedule& a, const schedule& b);

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);	

	int num;
	cin >> num;

	schedule studies[100000];

	for (int i = 0; i < num; ++i) 
		cin >> studies[i].start >> studies[i].end;

	sort(studies, studies + num, comp2);

	for (int i = 0; i < num; ++i)
		cout << "(" << studies[i].start << ", " << studies[i].end << ")" << endl;
	int result = 1;
	const schedule* pSchedule = &studies[0];

	for (int i = 1; i < num; ++i)
		if (studies[i].start >= pSchedule->end) {
			pSchedule = &studies[i];
			++ result;
		}

	cout << result << endl;

	return 0;
}

bool comp2(const schedule& a, const schedule& b) 
{
	if (a.end == b.end) return a.start < b.start;
	else return a.end < b.end;
}
