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
            cout << "size of s: " << s.size() << endl;
        }
        else{
            
            if(str[i] == ')'){
                if(s.top() == 'n'){
                    while(s.top() == 'n'){
                        s.pop();
                        tmp += s_num.top();
                        s_num.pop();
                        cout << "size of s: " << s.size() << endl;
                        cout << "size of s_num: " << s_num.size() << endl;
                    }
                }
                else{
                    tmp = 1;
                }
                
                if(s.top() == '('){
                    s.pop();
                    s.push('n');
                    s_num.push(tmp * 2);
                    cout << "size of s: " << s.size() << endl;
                    cout << "size of s_num: " << s_num.size() << endl;
                }
                else{
                    wrong = 1;
                    break;
                }
            }


            else{
                if(s.top() == 'n'){
                    while(s.top() == 'n'){
                        s.pop();
                        tmp += s_num.top();
                        s_num.pop();
                        cout << "size of s: " << s.size() << endl;
                        cout << "size of s_num: " << s_num.size() << endl;
                    }
                }
                else{
                    tmp = 1;
                }
                
                if(s.top() == '['){
                    s.pop();
                    s.push('n');
                    s_num.push(tmp * 3);
                    cout << "size of s: " << s.size() << endl;
                    cout << "size of s_num: " << s_num.size() << endl;
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
    else{
    while(s_num.size() != 0){
            sum += s_num.top();
            s_num.pop();
            cout << "size of s_num: " << s_num.size() << endl;
        }
    cout << sum << endl;
    }
}
