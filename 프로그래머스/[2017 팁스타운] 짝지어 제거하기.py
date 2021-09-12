def solution(s):
    
    result = []

    for i in s:
        if len(result) == 0:
            result.append(i)
        elif result[-1] == i:
            result.pop()
        else:
            result.append(i)

    return 1 if len(result) == 0 else 0