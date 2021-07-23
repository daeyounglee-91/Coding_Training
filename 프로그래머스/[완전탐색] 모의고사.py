def solution(answers):
    answer = []
    arr = [0,0,0]
    max = 0

    answer1 = [1,2,3,4,5]
    answer2 = [2,1,2,3,2,4,2,5]
    answer3 = [3,3,1,1,2,2,4,4,5,5]

    for i in range(0,len(answers)):
        if answer1[i%len(answer1)] == answers[i]:
            arr[0] += 1
            if max < arr[0] : max = arr[0]
        if answer2[i%len(answer2)] == answers[i]:
            arr[1] += 1
            if max < arr[1] : max = arr[1]
        if answer3[i%len(answer3)] == answers[i]:
            arr[2] += 1
            if max < arr[2] : max = arr[2]

    for i in range(0,len(arr)):
        if max == arr[i]: answer.append(i+1)

    return answer