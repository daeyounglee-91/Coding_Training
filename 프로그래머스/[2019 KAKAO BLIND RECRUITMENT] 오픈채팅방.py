def solution(numbers, hand):
    answer = ''
    
    left = [0,3]
    right = [2,3]
    key = [[1,3],
        [0,0],[1,0],[2,0],
        [0,1],[1,1],[2,1],
        [0,2],[1,2],[2,2]]
    
    for number in numbers:
        if number == 1 or number == 4 or number == 7:
            answer += "L"
            left = key[number]

        elif number == 3 or number == 6 or number == 9:
            answer += "R"
            right = key[number]
        else:
            l = abs(left[0] - key[number][0]) + abs(left[1] - key[number][1])
            r = abs(right[0] - key[number][0]) + abs(right[1] - key[number][1])
            if l < r:
                answer += "L"
                left = key[number]
            elif l > r:
                answer += "R"
                right = key[number]
            else:
                if hand == "right":
                    answer += "R"
                    right = key[number]
                else:
                    answer += "L"
                    left = key[number]
                    
        print("l : {0}, r : {1} number : {2}".format(left,right,number))
    
    return answer

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))