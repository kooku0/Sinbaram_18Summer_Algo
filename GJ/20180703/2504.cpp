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
    int prev = 1;
    bool isPushed = true;
    for(auto i : str){
        if(i == '(' || i == '['){
            s.push(i);
            isPushed = true;
        }
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
            }
            else{
                if(i == ')' || s.empty()){
                    state = false;
                    break;
                }
                s.pop();
            } // end of if

            if(i == ')') op.push(2);
            else op.push(3);
            isPushed = false;
        } // end of if

        if(op.top()){
            if(isPushed){
                result += prev;
                prev = 1;
            }
            else{
                prev *= op.top();
                op.pop();
            } // end of if
        }
    } // end of for
    if(!s.empty()) state = false;
    if(state == false) cout << 0 << endl;
    else cout << result << endl;
}
