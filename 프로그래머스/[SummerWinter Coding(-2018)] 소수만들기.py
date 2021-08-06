import itertools

def check(num):

    for i in range(2,num):
        if num % i == 0: return False

    return True

def solution(nums):
    answer = 0

    for i in list(itertools.combinations(nums,3)):
        if check(i[0] + i[1] + i[2]) == True:
            answer += 1

    return answer