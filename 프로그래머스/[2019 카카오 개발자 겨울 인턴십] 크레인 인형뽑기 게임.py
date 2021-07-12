def solution(board, moves):
    answer = 0
    box = []

    for move in moves:
        move -= 1

        for i in range(len(board)):
            if board[i][move] <= 0:
                continue

            if len(box) > 0 and (box[len(box) - 1] == board[i][move]):
                box.pop()
                answer += 2
            else:
                box.append(board[i][move])
            board[i][move] = 0
            break
        
        # print(box)

        # for b in board:
        #     print(b)
        # print()

    return answer

print(solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],[1,5,3,5,1,2,1,4]))

'''
[0,0,0,0,0],
[0,0,1,0,3],
[0,2,5,0,1]
[4,2,4,4,2]
[3,5,1,3,1]
'''