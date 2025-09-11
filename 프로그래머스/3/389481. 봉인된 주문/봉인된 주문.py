import heapq

def spell_to_num(spell):
    degree = 0
    result = 0
    for c in reversed(spell):
        result += pow(26, degree) * (ord(c) - ord('a') + 1)
        degree += 1
    return result

def num_to_spell(num):
    spell = []
    while num > 0:
        num -= 1                     # 1-based → 0-based 조정
        spell.append(chr(ord('a') + (num % 26)))
        num //= 26
    return ''.join(reversed(spell))

def solution(n, bans):
    count = 0
    pq = []
    
    bans.sort()
    for b in bans:
        heapq.heappush(pq, spell_to_num(b))
        
    
    bound = 0
    while pq and pq[0] <= n:
        n += 1
        heapq.heappop(pq)
        
    
        
    return num_to_spell(n)
    