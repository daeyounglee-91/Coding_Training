def solution(left, right):
    num = [0]
    answer = 0

    for i in range(1,right+1):
        count = 0
        for j in range(1,right+1):
            if i % j == 0 :
                count += 1
        num.append(count)
    
    print(num)

    for i in range(left,right+1):
        if num[i] % 2 == 0:
            answer += i
        else:
            answer -= i

    return answer