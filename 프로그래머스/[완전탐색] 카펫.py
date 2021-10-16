def solution(brown, yellow):
    answer = []
    num = brown + yellow
    for i in range(num,2,-1): # 가로
        if num % i == 0:
            a = num // i
            if yellow == (i-2)*(a-2):
                return [i, a]
    
    return answer