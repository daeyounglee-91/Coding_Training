def solution(numbers):
    answer = []
    temp = []

    for i in range(0,len(numbers) - 1):
        for j in numbers[i+1:]:
            temp.append(numbers[i]+j)

    answer = list(set(temp))
    answer = sorted(answer)

    return answer