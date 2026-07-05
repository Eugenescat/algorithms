def can_make_balanced(code):
    freq = {}
    
    # iterate over all the chars
        #put in freq_map 
    for char in code:
        freq[char] = freq.get(char, 0) + 1
        
    #check if the value is same for all the chars
    
    counts = list(freq.values())
    
    # let the smallest freq be the target
    target = min(counts)
    
    gap = 0
    for n in counts:
        gap += (n - target)
    if gap == 1:
        return True
    return False


code1 = "arghh"
code2 = "haha"
code3 = "smallest"

print(can_make_balanced(code1)) 
print(can_make_balanced(code2))
print(can_make_balanced(code3))