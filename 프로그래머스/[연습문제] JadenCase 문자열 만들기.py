def solution(s):
    # answer = ''

    # temp = str(s).lower().split(" ")

    # for i in temp:
    #     answer += i.capitalize() + " "

    # return answer[0:-1]

    return ' '.join(w.capitalize() for w in s.split(" "))