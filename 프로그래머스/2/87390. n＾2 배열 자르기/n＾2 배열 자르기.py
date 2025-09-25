def solution(n, left, right):
    # arr = [[0 for _ in range(n)] for _ in range(n)]
    # for i in range(1, n + 1):
    #     for j in range(i):
    #         arr[i - 1][j] = i
    #         arr[j][i - 1] = i
            
#     arr = [0 for _ in range(n * n)]
#     for i in range(1, n + 1):
#         for j in range(i):
#             arr[(i - 1) * n + j] = i
#             arr[i - 1 + n * j] = i
            
#     return arr[left:right + 1]
    
    answer=[]
    for i in range(left, right + 1):
        x = i // n
        y = i % n
        answer.append(max(x, y) + 1)
    return answer
            
