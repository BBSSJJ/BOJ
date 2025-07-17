def solution(n, lost, reserve):
    answer = n

    lost_set = set(lost)
    reserve_set = set(reserve)

    lost = sorted(list(lost_set - reserve_set))
    reserve = sorted(list(reserve_set - lost_set))

    answer -= len(lost)

    lIdx = 0
    rIdx = 0

    while lIdx < len(lost) and rIdx < len(reserve):
        if reserve[rIdx] < lost[lIdx] - 1:
            rIdx += 1
        elif reserve[rIdx] > lost[lIdx] + 1:
            lIdx += 1
        else:
            answer += 1
            lIdx += 1
            rIdx += 1

    return answer