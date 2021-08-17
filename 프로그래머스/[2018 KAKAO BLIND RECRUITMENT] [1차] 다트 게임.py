def solution(dartResult):
    score = []
    bonus = {'S': 1, 'D': 2, 'T': 3}
    option = {'*' : 2, '#' : -1}

    dartResult = dartResult.replace("10","A")
    
    for i in dartResult:
        if i.isdigit() or i == 'A':
            score.append(10 if i == 'A' else int(i))
        elif i == 'S' or i == 'D' or i == 'T':
            score[len(score)-1] = score[len(score)-1] ** bonus[i]
        elif i == '*':
            if len(score) != 1 : score[len(score)-2] = score[len(score)-2] * 2
            score[len(score)-1] = score[len(score)-1] * 2
        else:
            score[len(score)-1] = score[len(score)-1] * -1
    
    return sum(score)