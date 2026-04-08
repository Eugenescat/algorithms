
def solution(input: str):
    i, j = 0, 0
    freq = dict() # 记录窗口中出现次数
    length = 0
    
    while j <= i and i < len(input):
        cur = input[i]
        freq[cur] = freq.get(cur, 0) + 1
        
        # 如果cur出现次数大于1，则需要收缩窗口直至不重复
        while freq[cur] > 1:
            freq[input[j]] -= 1
            j += 1
        
        length = max(length, i - j + 1)    
        i += 1
    
    return length