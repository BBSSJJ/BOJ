#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, L, p, q;
int answer = 1;
int direction = 0;
char o;
int board[101][101];
int dx[] = {0, 1, 0, -1};  // 오 아 왼 위 순서
int dy[] = {1, 0, -1, 0};
queue<pair<int, char>> order;
deque<pair<int, int>> snake;

void moveTo(int x, int y) {
    int tail_x = snake.back().first;
    int tail_y = snake.back().second;
    if (board[x][y] != 2) {
        board[tail_x][tail_y] = 0;
        snake.pop_back();
    }
    board[x][y] = 1;
    snake.push_front({x, y});
}

bool OOB(int x, int y) {
    if (x < 1 || y < 1 || x > N || y > N) return true;
    if (board[x][y] == 1) return true;
    return false;
}

void change_direction(char O) {
    if (O == 'D') direction = (direction + 1) % 4;
    if (O == 'L') direction = (direction + 3) % 4;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> p >> q;
        board[p][q] = 2;  // 사과는 2
    }
    board[1][1] = 1;  // 뱀은 1
    snake.push_front({1, 1});

    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> p >> o;
        order.push({p, o});
    }

    direction = 0;
    answer = 0;
    while (1) {
        int cur_x = snake.front().first;
        int cur_y = snake.front().second;
        int next_x = cur_x + dx[direction];
        int next_y = cur_y + dy[direction];
        if (OOB(next_x, next_y)) break;

        // move
        moveTo(next_x, next_y);

        answer++;

        if (answer == order.front().first) {
            change_direction(order.front().second);
            order.pop();
        }
    }

    cout << answer + 1 << "\n";
}