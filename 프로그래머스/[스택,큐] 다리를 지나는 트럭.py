def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge_weight = [0] * bridge_length

    while(len(truck_weights) != 0):
        bridge_weight.pop(0)
        if sum(bridge_weight) + truck_weights[0] > weight:
            bridge_weight.append(0)
        else:
            bridge_weight.append(truck_weights[0])
            truck_weights.pop(0)
        answer += 1
    
    answer += bridge_length

    return answer