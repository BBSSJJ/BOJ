#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x;
vector<int> numbers;
vector<int> sorted;
vector<int> pressed;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> x;
        numbers.push_back(x);
        sorted.push_back(x);
    }

    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < N; i++){
        if(i == 0){
            pressed.push_back(sorted[i]);
        }
        else{
            if(sorted[i] != sorted[i - 1]){
                pressed.push_back(sorted[i]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        int cur = numbers[i];
        cout << lower_bound(pressed.begin(), pressed.end(), cur) - pressed.begin() << " ";
    }
}
