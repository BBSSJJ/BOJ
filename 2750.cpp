#include <iostream>
using namespace std;

int arr[1100];
int N, n;

void insertionSort(int* array, int N){
    int key, i, j;
    for(i = 1; i < N; i++){
        key = array[i];
        for(j=1; j <= i; j++){
            if(array[i-j] > key){
                array[i-j+1] = array[i-j];
            }
            else
                break;
        }
        array[i-j+1] = key;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> n;
        arr[i] = n;
    }
    insertionSort(arr, N);

    for(int i= 0; i<N; i++){
        cout << arr[i] << endl;
    }
}