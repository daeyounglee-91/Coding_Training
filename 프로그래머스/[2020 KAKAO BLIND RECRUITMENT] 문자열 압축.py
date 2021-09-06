def solution(s):
    answer = 1000

    if len(s) == 1:
        return 1
    
    for i in range(1,len(s)):
        count = 1
        temp = s[:i]
        result = ""

        for j in range(i,len(s),i):
            if temp == s[j:j+i]:
                count += 1
            else:
                if count == 1:
                    count = ""
                result += str(count) + temp
                temp = s[j:j+i]
                count = 1

        if count == 1:
            count = ""
        result += str(count) + temp
        temp = s[j:j+i]
        count = 1

        if answer > len(result):
            answer = len(result)

    return answer