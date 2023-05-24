#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, n;
int M;
vector<int> city;
int calculate(int mid_val)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (city[i] >= mid_val)
        {
            sum += mid_val;
        }
        else
        {
            sum += city[i];
        }
    }
    return sum;
}

int main()
{
    int start = 0;
    int end = 0;
    int mid = 0;
    int result = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        city.push_back(n);
        end = max(end, n);
    }

    cin >> M;

    while (start <= end)
    {
        mid = (start + end) / 2;
        int sum = calculate(mid);
        if (sum > M)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            result = mid;
        }
    }
    cout << result;
}