def solution(n):
    num = bin(n).count('1')
    
    for i in range(n+1,2000000):
        if bin(i).count('1') == num: return i