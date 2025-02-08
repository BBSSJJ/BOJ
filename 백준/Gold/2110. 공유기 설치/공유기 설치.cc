#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> house;

int N, C, x; // 집 개수 N, 공유기 개수 C, 집좌표 x

bool success(int hop)
{
    int start = 0;
    int count = 1;

    for (int i = 0; i < N; i++)
    {
        if (house[start] + hop <= house[i])
        {
            start = i;
            count++;
        }
    }

    return count >= C;
}

int main()
{
    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        house.push_back(x);
    }

    sort(house.begin(), house.end());

    int hop_end = (house[N - 1] - house[0] + 1) * 2 / C;
    int hop_start = 0;

    int answer = 0;
    while (hop_start <= hop_end)
    {
        int hop_mid = (hop_end + hop_start) / 2;
        if (success(hop_mid))
        {
            answer = hop_mid;
            hop_start = hop_mid + 1;
        }
        else{
            hop_end = hop_mid - 1;
        }
    }

    cout << answer;
}