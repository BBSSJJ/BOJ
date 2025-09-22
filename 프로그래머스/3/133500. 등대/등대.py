# edge가 n-1개 이므로 사이클이 없다

# 자신이 빛나는지 리턴

import sys
sys.setrecursionlimit(10**6)

def dfs(cur, before):
    global graph, light
        
    for next in graph[cur]:
        if next == before: continue
        if len(graph[next]) == 1:
            light[cur] = True
        dfs(next, cur)
        if light[next] == False:
            light[cur] = True
    
    return light[cur]
    

def solution(n, lighthouse):
    global graph, answer, light, visited
    answer = 0
    graph = [[] for _ in range(n + 1)]  # 1번부터 n번까지
    light = [False for _ in range(n + 1)]
    
    
    for edge in lighthouse:
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])
    
    dfs(1, 0)
    
    for i in range(1, n + 1):
        if light[i]: answer += 1
    
    return answer