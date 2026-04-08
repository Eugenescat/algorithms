
def solution(input: list[list[int]]):
    r, c = len(input) - 1, len(input[0]) - 1
    top, right, bottom, left = 0, c, r, 0
    res = []
    
    while top <= bottom and left <= right:
        for i in range(left, right + 1, 1):
            res.append(input[top][i])
        top += 1
        
        for i in range(top, bottom + 1, 1):
            res.append(input[i][right])
        right -= 1
        
        if top <= bottom:
            for i in range(right, left - 1, -1):
                res.append(input[bottom][i])
            bottom -= 1
        
        if left <= right:
            for i in range(bottom, top - 1, -1):
                res.append(input[i][left])
            left += 1
    
    return res