#include <iostream>
#include <string>

using namespace std;
int n;
char map[65][65];

string divide(int x, int y, int N)
{
    if (N == 1)
    {
        string s;
        s = s + map[x][y];
        return s;
    }

    // 네 조각으로 나눈다
    int a_x = x;
    int a_y = y;
    int b_x = x;
    int b_y = y + N / 2;
    int c_x = x + N / 2;
    int c_y = y;
    int d_x = x + N / 2;
    int d_y = y + N / 2;

    // 네 조각이 모두 동일 할 경우 하나로 합친다.
    string a_string = divide(a_x, a_y, N / 2);
    string b_string = divide(b_x, b_y, N / 2);
    string c_string = divide(c_x, c_y, N / 2);
    string d_string = divide(d_x, d_y, N / 2);
    if (a_string == b_string && b_string == c_string && c_string == d_string)
    {
        if (a_string == "0" || a_string == "1")
        {
            return a_string;
        }
        else
        {
            return "(" + a_string + b_string + c_string + d_string + ")";
        }
    }
    else
    {
        return "(" + a_string + b_string + c_string + d_string + ")";
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    std::cout << divide(0, 0, n);
}