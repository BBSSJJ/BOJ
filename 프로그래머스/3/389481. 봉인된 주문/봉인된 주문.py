def solution(n, bans):
    
    def convert_to_spell(n):
        spell_idx = []
        while n > 0:
            idx = (n - 1) % 26 + 1   # 1~26 범위 보장
            spell_idx.append(idx)
            n = (n - 1) // 26        # 0이 없는 26진법이므로 (n-1) 처리
        string = ''.join(chr(i + 96) for i in reversed(spell_idx))
        return string
    
    og = convert_to_spell(n)
    bans.sort(key=lambda x: (len(x), x))

    for ban in bans :
        if len(ban) < len(og) :
            n += 1
            og = convert_to_spell(n)
        elif len(ban) == len(og) and ban <= og :
            n += 1
            og = convert_to_spell(n)
    return convert_to_spell(n)