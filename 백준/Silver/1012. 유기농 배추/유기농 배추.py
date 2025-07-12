from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def out_of_bound(x, y, N, M):
    return x < 0 or y < 0 or x >= N or y >= M

def bfs(x, y, N, M, land, visited):
    que = deque()
    que.append([x, y])
    visited[x][y] = True
    while que:
        cur = que.popleft()
        for i in range(4):
            nx = cur[0] + dx[i]
            ny = cur[1] + dy[i]
            if out_of_bound(nx, ny, N, M) or visited[nx][ny] == True or land[nx][ny] == 0: continue
            visited[nx][ny] = True
            que.append([nx, ny])
    

def check(N, M, land):
    result = 0
    visited = [[False] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if land[i][j] == 1 and visited[i][j] == False:
                bfs(i, j, N, M, land, visited)
                result += 1
    return result


T = int(input())

for t in range(T):
    M, N, K = map(int, input().split())

    land = [[0] * M for _ in range(N)]
    for i in range(K):
        y, x = map(int, input().split())
        land[x][y] = 1
    
    print(check(N, M, land))
    
    
    
