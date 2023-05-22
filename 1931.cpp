#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, p, q;
vector<pair<int, int>> v;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p >> q;
        v.push_back({q, p});
    }
    sort(v.begin(), v.end());

    int answer = 0;
    int before_end_time = 0;
    for (int i = 0; i < N; i++)
    {
        if(v[i].second >= before_end_time){
            answer++;
            before_end_time = v[i].first;
        }
    }
    cout << answer << endl;
}