#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkOverlap(const vector<pair<int, int>>& pv, const pair<int, int>& p2) ;
bool comp(const pair<int, int>& l, const pair<int, int>& r);

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);	

	int num;
	cin >> num;

	vector<pair<int, int>> studies(num);

	for (int i = 0; i < num; ++i) 
		cin >> studies[i].first >> studies[i].second;

	sort(studies.begin(), studies.end(), comp);
	vector<pair<int, int>> result_vec;

	for (int i = 0; i < num; ++i) {
		//���⼭ �ɸ��� �ð��� ���� �͵� �߿� �ִ��� ���� ä���������ִ� ��츦 ���ؼ� �ϸ� �ȴ�.
		
		if (result_vec.empty() || !checkOverlap(result_vec, studies[i]))
			result_vec.push_back(make_pair(studies[i].first, studies[i].second));
	}

	for (int i = 0; i < result_vec.size(); ++i)
		cout << "(" << result_vec[i].first << ", " << result_vec[i].second << ")" << endl;
	cout << result_vec.size() << endl;

	return 0;
}

bool checkOverlap(const vector<pair<int, int>>& pv, const pair<int, int>& p2) 
{
	for (int i = 0; i < pv.size(); ++i) {
		if (pv[i].second > p2.first && pv[i].first < p2.second ||
	    		pv[i].first < p2.second && p2.first < pv[i].second)
			return true;
	}
	return false;
}

bool comp(const pair<int, int>& l, const pair<int, int>& r)
{
	if (l.second - l.first < r.second - r.first)
		return true;
	else 
		return false;
}
