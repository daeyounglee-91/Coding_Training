def solution(clothes):
    answer = 1
    temp = {}
    
    for elem in clothes:
        if elem[1] in temp.keys():     
            temp[elem[1]].append(elem[0])
        else:
            temp[elem[1]] = [elem[0]]
    
    for key in temp.keys():
        answer = answer * (len(temp[key]) + 1)
    
    return answer - 1