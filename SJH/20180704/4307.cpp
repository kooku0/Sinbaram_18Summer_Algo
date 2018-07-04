#include <iostream>
#include <vector>



using namespace std;


int main(void)
{
	int testnum, length, antnum;
	cin >> testnum;

	vector<int> min_vec(testnum, 0);
	vector<int> max_vec(testnum, 0);
	
	int temp_pos;

	for (int i = 0; i < testnum; ++i) {
		cin >> length >> antnum;

		for (int j = 0; j < antnum; ++j) {
			cin >> temp_pos;
			int dist_middle = length - temp_pos > temp_pos ? temp_pos : length - temp_pos; 
			int dist_end = temp_pos > length - temp_pos ? temp_pos : length - temp_pos;

			if (min_vec[i] < dist_middle)
			      	min_vec[i] = dist_middle;
			if (max_vec[i] < dist_end)
				max_vec[i] = dist_end;	
		}
	}	

	for (int i = 0; i < testnum; ++i)
		cout << min_vec[i] << ' ' << max_vec[i] << endl;

	return 0;
}
