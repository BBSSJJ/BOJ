// STL list
#include <list>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

list<char> charlist;
char O;
int M;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    cin >> M;

    for (char c : str)
    {
        charlist.push_back(c);
    }

    auto cursor = charlist.end();

    for (int i = 0; i < M; i++)
    {
        cin >> O;
        if (O == 'L')
        {
            if (cursor != charlist.begin())
                cursor--;
        }
        else if (O == 'D')
        {
            if (cursor != charlist.end())
                cursor++;
        }
        else if (O == 'B')
        {
            if (cursor != charlist.begin())
            {
                cursor--;
                cursor = charlist.erase(cursor);
            }
            else
                continue;
        }
        else if (O == 'P')
        {
            char o;
            cin >> o;
            charlist.insert(cursor, o);
        }
    }

    for (char c : charlist)
    {
        cout << c;
    }
}