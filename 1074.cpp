#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int count;
int travel(int N, int r, int c)
{
    if (N == 0)
    {
        return 0;
    }
    int half = pow(2, N - 1);
    if (r < half && c < half)
        return travel(N - 1, r, c);
    else if (r < half && c >= half)
        return half * half + travel(N - 1, r, c - half);
    else if (r >= half && c < half)
        return 2 * half * half + travel(N - 1, r - half, c);
    else if (r >= half && c >= half)
        return 3 * half * half + travel(N - 1, r - half, c - half);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;

    cin >> N;
    cin >> r >> c;

    cout << travel(N, r, c);
}