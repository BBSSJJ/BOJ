// https://www.acmicpc.net/problem/5430
// string indexing하는거 주의!
#include <iostream>
#include <string.h>
#include <deque>
#include <vector>

using namespace std;

int T, n;

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string p;
        deque<string> dq;
        string a;
        int direction = 0; // 0이면 왼쪽to오른쪽 1이면 오른쪽to왼쪽
        int error = 0;

        cin >> p;
        cin >> n;
        cin >> a;
        int k = 1;

        int alen = a.length();

        string s = "";
        for (int j = 0; j < alen; j++)
        {
            if (isdigit(a[j]))
            {
                s += a[j];
            }
            else
            {
                if (!s.empty())
                {
                    dq.push_back(s);
                    s = "";
                }
            }
        }

        int plen = p.length();
        for (int j = 0; j < plen; j++)
        {
            if (p[j] == 'R')
            {
                direction = (direction == 0 ? 1 : 0);
            }
            else if (p[j] == 'D')
            {
                if (direction == 0 && !dq.empty())
                {
                    dq.pop_front();
                }
                else if (direction == 1 && !dq.empty())
                {
                    dq.pop_back();
                }
                else
                {
                    cout << "error" << endl;
                    error = 1;
                    break;
                }
            }
        }
        if (error)
        {
            continue;
        }
        int l = 0;
        cout << '[';
        if (direction == 0)
        {
            if (dq.size() == 0)
            {
                cout << "]";
            }
            else
            {
                for (l = 0; l < dq.size() - 1; l++)
                {
                    cout << dq[l] << ",";
                }
                cout << dq[l] << "]";
            }
        }
        else if (direction == 1)
        {
            if (dq.size() == 0)
            {
                cout << "]";
            }
            else
            {
                for (l = dq.size() - 1; l > 0; l--)
                {
                    cout << dq[l] << ",";
                }
                cout << dq[l] << "]";
            }
        }
        cout << "\n";
    }
}