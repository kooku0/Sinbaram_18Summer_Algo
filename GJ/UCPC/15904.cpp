#include<iostream>
#include<string>
using namespace std;

#define MAX_SIZE 1001

int main(void){
	string find = "UCPC";
	string input; getline(cin, input);

	int now = 0;
	for(const auto& i : input){
		if(i == find[now]) now++;
	}
	if(now == 4) cout << "I love UCPC" << endl;
	else		 cout << "I hate UCPC" << endl;
	return 0;
}