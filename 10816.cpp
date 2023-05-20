#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, n;
vector<int> card;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        card.push_back(n);
    }
    sort(card.begin(), card.end());

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> n;

        vector<int>::iterator start = lower_bound(card.begin(), card.end(), n);
        vector<int>::iterator end = upper_bound(card.begin(), card.end(), n);
        cout << end - start << " ";
    }
}