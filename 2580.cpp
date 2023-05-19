#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blank;
int blank_visited[81];

bool check_square(int x, int y)
{
    int x_block = x / 3;
    int y_block = y / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int compare_x = x_block * 3 + i;
            int compare_y = y_block * 3 + j;
            if (compare_x != x && compare_y != y && sudoku[compare_x][compare_y] == sudoku[x][y])
                return false;
        }
    }
    return true;
}

bool check_line(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (x != i && sudoku[x][y] == sudoku[i][y])
            return false;
    }
    for (int j = 0; j < 9; j++)
    {
        if (y != j && sudoku[x][y] == sudoku[x][j])
            return false;
    }
    return true;
}

bool flag = 0;

void backt(int n)
{
    // cout << "int backt, blank number is " << n << endl;
    int cur_x = blank[n].first;
    int cur_y = blank[n].second;
    for (int i = 1; i <= 9; i++)
    {
        // cout << "in blank " << n << ", selected " << cur_x << " " << cur_y << " is " << i << endl;
        sudoku[cur_x][cur_y] = i;
        if (check_line(cur_x, cur_y) == false || check_square(cur_x, cur_y) == false)
            continue;
        if (n == blank.size() - 1)
        {
            for (int p = 0; p < 9; p++)
            {
                for (int q = 0; q < 9; q++)
                {
                    cout << sudoku[p][q] << " ";
                }
                cout << "\n";
            }
            flag = 1;
            return;
        }
        backt(n + 1);
        sudoku[cur_x][cur_y] = 0;
        if (flag)
            return;
    }
    sudoku[cur_x][cur_y] = 0;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                blank.push_back({i, j});
        }
    }

    backt(0);
}