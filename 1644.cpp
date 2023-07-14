// 1644

#include <iostream>
#include <vector>

using namespace std;

int N;
int answer;

vector<int> prime_numbers;

int main()
{
    cin >> N;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * 2; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i <= N; i++)
    {
        if (is_prime[i])
            prime_numbers.push_back(i);
    }

    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (N == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if (N == 3)
    {
        cout << 1 << endl;
        return 0;
    }
    if (N == 4)
    {
        cout << 0 << endl;
        return 0;
    }

    int ptr_start = 0;
    int ptr_end = 1;
    int sum = prime_numbers[ptr_start] + prime_numbers[ptr_end];
    if (is_prime[N])
        answer++;

    while (ptr_start < ptr_end)
    {
        if (sum > N)
        {
            sum -= prime_numbers[ptr_start];
            ptr_start++;
        }
        else if (sum < N)
        {
            ptr_end++;
            sum += prime_numbers[ptr_end];
        }
        else
        {
            answer++;
            ptr_end++;
            sum += prime_numbers[ptr_end];
        }
    }

    cout << answer << endl;
}