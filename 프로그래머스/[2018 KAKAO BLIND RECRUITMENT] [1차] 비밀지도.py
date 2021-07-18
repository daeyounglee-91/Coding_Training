def solution(n, arr1, arr2):
    answer = []

    bin1 = []
    bin2 = []
    for i in arr1 :
        bin1.append(format(i,'b').zfill(n))
        
    for i in arr2 :
        bin2.append(format(i,'b').zfill(n))

    for i,j in zip(bin1, bin2):
        s = ""
        for k,l in zip(i, j):
            if k == "1" or l == "1":
                s += "#"
            else :
                s += " "
        answer.append(s)
        
    return answer