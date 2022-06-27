#include <iostream>
#include <string>
#include <deque>

using namespace std;

int T, n;



int main(){
    cin >> T;
    for(int i = 0; i < T; i ++){
        string p;
        deque<int> dq;
        string a;

        cin >> p;
        cin >> n;
        cin >> a;
        int k = 1;

        while(n != 0){
            dq.push_back(a[k]);
            k++;
        }

        for(int j = 0; j < p.length(); j++){
        }
    }
}