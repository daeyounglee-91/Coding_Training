def solution(n, lost, reserve):
    temp_res = set(reserve) - set(lost)
    temp_lost = set(lost) - set(reserve)
    
    for i in temp_res:
        if i - 1 in temp_lost:
            temp_lost.remove(i - 1)
        elif i + 1 in temp_lost:
            temp_lost.remove(i + 1)
    
    return n - len(temp_lost)