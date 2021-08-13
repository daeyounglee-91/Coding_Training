def solution(lottos, win_nums):
    def getScore(num):
        if num == 6:
            return 1
        elif num == 5:
            return 2
        elif num == 4:
            return 3
        elif num == 3:
            return 4
        elif num == 2:
            return 5
        else:
            return 6

    answer = []
    count = 0
    for i in lottos:
        if i in win_nums:
            count += 1
      
    answer.append(getScore(count + lottos.count(0)))
    answer.append(getScore(count))

    return answer