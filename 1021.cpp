// https://www.acmicpc.net/problem/1021
#include <iostream>
#include <deque>
using namespace std;

int N, M, n, count, tmp, idx, s;
deque<int> d;

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        d.push_back(i);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> n;
        s = d.size();
        if (d.front() != n)
        {
            for (int j = 0; j < s; j++)
            {
                if (d[j] == n)
                {
                    idx = j;
                }
            }
            if (idx <= s / 2)
            {
                while (d.front() != n)
                {
                    tmp = d.front();
                    d.pop_front();
                    d.push_back(tmp);
                    count += 1;
                }
            }
            else
            {
                while (d.front() != n)
                {
                    tmp = d.back();
                    d.pop_back();
                    d.push_front(tmp);
                    count += 1;
                }
            }
        }
        d.pop_front();
    }
    cout << count << "\n";
}

// #include <iostream>
// #include <deque>
// using namespace std;

// int N, M, n, c, count, half, tmp;
// deque<int> d;

// int main()
// {
//     cin >> N >> M;
//     for (int i = 1; i <= N; i++)
//     {
//         d.push_back(i);
//     }

//     for (int i = 0; i < M; i++)
//     {
//         cin >> n;
//         while (d.front() != n)
//         {
//             tmp = d.front();
//             d.pop_front();
//             d.push_back(tmp);
//             c += 1;
//         }
//         count += (c < d.size() - c ? c : d.size() - c);
//         c = 0;
//         d.pop_front();
//     }
//     cout << count << "\n";
// }