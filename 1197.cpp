#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, A, B, C, answer;
int parent[10001];
vector<pair<int, pair<int, int>>> weight;

int final_parent(int x)
{
    while (parent[x] != x) x = parent[x];
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> A >> B >> C;
        weight.push_back({C, {A, B}});
    }
    sort(weight.begin(), weight.end());

    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }


    for (int i = 0; i < E; i++)
    {
        int a = weight[i].second.first;
        int b = weight[i].second.second;
        int w = weight[i].first;

        int final_parent_a = final_parent(a);
        int final_parent_b = final_parent(b);


        if (final_parent_a == final_parent_b)
            continue;
        else
        {
            parent[final_parent_b] = final_parent_a;
            answer += w;
        }
    }

    cout << answer << "\n";
}