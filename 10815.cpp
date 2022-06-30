// https://www.acmicpc.net/problem/10815
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, n;
int deck[500001];
vector<int> result;

int search(int n, int start, int end){
    while(start <= end){
        int mid = (start + end) / 2;
        if(deck[mid] == n){
            return 1;
        }
        else if(deck[mid] > n){
            end = mid - 1;
        }
        else if(deck[mid] < n){
            start = mid + 1;
        }
    }
    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        deck[i] = n;
    }

    sort(deck, deck + N);

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> n;
        result.push_back(search(n, 0, N-1));
    }

    for(int i = 0; i < M; i++){
        cout << result[i] << " ";
    }

}