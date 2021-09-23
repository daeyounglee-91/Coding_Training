def DFS(array, numbers, target, size):
    answer = 0

    if len(array) == size:
        if sum(array) == target:
            return 1
        else: 
            return 0
    
    num = numbers.pop()

    for i in [-1,1]:
        array.append(i * num)
        answer += DFS(array, numbers, target, size)    
        array.pop()

    numbers.append(num)
    return answer

def solution(numbers, target):
    return DFS([], numbers, target, len(numbers))