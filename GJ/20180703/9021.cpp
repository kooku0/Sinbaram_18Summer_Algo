#include<iostream>
#include<stack>
using namespace std;

int main(){
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        stack<char> s;
        string result = "YES";
        string str; cin >> str;
        for(auto i : str){
            if(i == '(')
                s.push(i);
            else{
                if(s.empty()){
                    result = "NO";
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) result = "NO";
        cout << result << endl;
    }
    return 0;
}
