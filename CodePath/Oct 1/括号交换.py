import math
def min_swaps(s):
    unmatched = 0
    for k in s:
        if k == ']' and unmatched > 0:
            unmatched -= 1
        elif k == '[':
            unmatched += 1
        
    return math.ceil(unmatched / 2)

print(min_swaps("][][")) 
print(min_swaps("]]][[[")) 
print(min_swaps("[]"))  

# 解释：剩余的 2k 长度的 "]]][[[" 需要几次交换」,而 k 个右括号里只有前一半需要被换走(后一半会被前一半的交换顺带修好),所以是 ⌈k/2⌉。这不算严格证明,但作为记忆线索够用。