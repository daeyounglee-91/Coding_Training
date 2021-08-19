def solution(n):
    if n < 2: return 1
    
    nums = [1,1]
    
    for i in range(2,n):
        nums.append((nums[i-2] + nums[i-1])%1234567)
        
    return nums[n-1]