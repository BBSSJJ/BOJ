def check(want, number, window):
    for i, w in enumerate(want):
        if number[i] != window.get(w, 0): return 0
    return 1
    

def solution(want, number, discount):
    answer = 0
    
    n = sum(number)
    window = {}
    for i in range(n):
        window[discount[i]] = window.get(discount[i], 0) + 1
    
    start = 0
    end = n - 1
    
    while end < len(discount):
        answer += check(want, number, window)
        
        window[discount[start]] -= 1
        start += 1
        end += 1
        if end < len(discount):
            window[discount[end]] = window.get(discount[end], 0) + 1
    
    return answer