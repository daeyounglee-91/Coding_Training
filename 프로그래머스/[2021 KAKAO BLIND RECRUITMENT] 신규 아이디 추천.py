def solution(new_id):
    new_id = str(new_id).lower()
    answer = ""

    for c in new_id:
        if c.isalnum() or c in '-_.':
            answer += c

    while ".." in answer:
        answer = answer.replace("..",".")

    if answer[0] == '.':
        answer = answer[1:]
    
    if len(answer) - 1 > 0 and answer[len(answer) - 1] == '.':
        answer = answer[:len(answer) - 1]

    if len(answer) == 0:
        answer += "a"

    if len(answer) >= 16:
        answer = answer[:15]
        
    if answer[len(answer) - 1] == '.':
        answer = answer[:len(answer) - 1]

    while len(answer) <= 2:
        answer += answer[len(answer) - 1]

    return answer