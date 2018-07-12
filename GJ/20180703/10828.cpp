#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    stack<int> s;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        if(temp == "push"){
            int value; cin >> value;
            s.push(value);
        }
        else if(temp == "pop"){
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            else
                cout << -1 << endl;
        }
        else if(temp == "size"){
                cout << s.size() << endl;
        }
        else if(temp == "empty"){
            cout << s.empty() << endl;
        }
        else if(temp == "top"){
            if(!s.empty())
                cout << s.top() << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
