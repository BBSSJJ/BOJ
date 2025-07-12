def dfs(cur, graph, visited):
    count = 1
    visited[cur] = True
    for next in graph[cur]:
        if visited[next] == True: continue
        count += dfs(next, graph, visited)
    return count

N = int(input())
E = int(input())

graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)

for i in range(E):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

print(dfs(1, graph, visited) - 1)

