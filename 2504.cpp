// https://www.acmicpc.net/problem/2504
// while, if같은 조건문에서 stack.top() 쓰는거 조심하자. 비어있을 경우 runtime error 발생!!!!!!!!!!
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack<char> s;
stack<int> s_num;
int wrong, sum, tmp;

int main(){
    cin >> str;
    int strlen = str.length();
    for(int i = 0; i < strlen; i++){
        tmp = 0;
        if(str[i] == '[' || str[i] == '('){
            s.push(str[i]);
        }
        else{
            if(str[i] == ')'){
                if(s.size() != 0 && s.top() == 'n'){
                    while(s.top() == 'n'){
                        s.pop();
                        tmp += s_num.top();
                        s_num.pop();
                        if(s.size() == 0)
                            break;
                    }
                }
                else{
                    tmp = 1;
                }
                
                if(s.size() != 0 && s.top() == '('){
                    s.pop();
                    s.push('n');
                    s_num.push(tmp * 2);
                }
                else{
                    wrong = 1;
                    break;
                }
            }


            else{
                if(s.size() != 0 && s.top() == 'n'){
                    while(s.top() == 'n'){
                        s.pop();
                        tmp += s_num.top();
                        s_num.pop();
                        if(s.size() == 0)
                            break;
                    }
                }
                else{
                    tmp = 1;
                }
                
                if(s.size() != 0 && s.top() == '['){
                    s.pop();
                    s.push('n');
                    s_num.push(tmp * 3);
                }
                else{
                    wrong = 1;
                    break;
                }
            }
        }
    }
    if(wrong){
        cout << 0 << endl;
        return 0;
    }
        while(s.top() == 'n'){
            s.pop();
            sum += s_num.top();
            s_num.pop();
            if(s.size() == 0){
                break;
            }
        }
        if(s.size() != 0 || s_num.size() != 0){
            cout << 0 << endl;
            return 0;
        }
    cout << sum << endl;
    
}
