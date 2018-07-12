#include<iostream>
#include<stack>
using namespace std;

void run();

int main(){
    run();
    return 0;
}

void run(){
    string str; cin >> str;
    int result = 0;
    stack<int> op;
    stack<char> s;
    bool state = true;
    for(auto i : str){
        if(i == '(' || i == '['){
            s.push(i);
        } // open case
        else{
            if(s.empty()){
                state = false;
                break;
            }
            char current = s.top();
            if(current == '('){
                if(i == ']' || s.empty()){
                    state = false;
                    break;
                }
                s.pop();
            } // bracket ']'
            else{
                if(i == ')' || s.empty()){
                    state = false;
                    break;
                }
                s.pop();
            } // bracket ')'
        } // close case


    } // end of for
    if(!s.empty()) state = false;
    if(state == false) cout << 0 << endl;
    else cout << result << endl;
}
