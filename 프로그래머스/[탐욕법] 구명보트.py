def solution(people, limit):
    answer = len(people)
    p = sorted(people,reverse = True)
    s,e = 0, len(p)-1
    while s < e : 
        if p[s]+p[e] <= limit :
            e-=1
            answer-=1
        s+=1
    return answer
