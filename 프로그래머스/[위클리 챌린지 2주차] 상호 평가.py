def getGrade(score):
    if score >= 90:
        return 'A'
    elif 80 <= score < 90:
        return 'B'
    elif 70 <= score < 80:
        return 'C'
    elif 50 <= score < 70:
        return 'D'
    else:
        return 'F'

def solution(table):
    answer = ''

    for i in range(0,len(table)):
        sum = 0
        min = 101
        max = 0

        for j in range(0,len(table)):
            if i == j: continue
            
            sum += table[j][i]
            if min > table[j][i]:
                min = table[j][i]
            if max < table[j][i]:
                max = table[j][i]

        count = len(table)

        if min <= table[i][i] <= max:
            sum += table[i][i]
        else:
            count -= 1
        answer += getGrade(sum/count)
        
    return answer