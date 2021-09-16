def solution(progresses, speeds):
    answer = []


    while(len(progresses) != 0):
        for i in range(0,len(progresses)):
            progresses[i] += speeds[i]
        
        count = 0
        while(len(progresses) != 0 and progresses[0] >= 100):
            count += 1
            progresses.pop(0)
            speeds.pop(0)

        if count != 0:
            answer.append(count)
            
    return answer