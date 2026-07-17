# version 1
# problem 3
# time: O(logn) space: O(1)
def find_frequency_positions(transmissions, target):
    if len(transmissions) == 0:
        return (-1, -1)
    
    l = 0
    r = len(transmissions) - 1
    
    while l < r:
        mid = (l + r) // 2
        if transmissions[mid] >= target: # shrink from right
            r = mid
        elif transmissions[mid] < target:
            l = mid + 1
    if transmissions[r] == target:
        start = r # store left side
    else:
        return (-1, -1)
    
    l = 0
    r = len(transmissions) - 1
    while l < r:
        mid = (l + r + 1) // 2 # to avoid l == l loop
        if transmissions[mid] > target: # shrink from right
            r = mid - 1
        elif transmissions[mid] <= target:
            l = mid
            
    return (start, r)
    
print(find_frequency_positions([5,7,7,8,8,10], 8))
print(find_frequency_positions([5,7,7,8,8,10], 6))
print(find_frequency_positions([], 0))
print(find_frequency_positions([5, 5, 5, 6, 6, 7, 8], 5))

# (3, 4)
# (-1, -1)
# (-1, -1)


# Problem 4: Smallest Letter Greater Than Target
def next_greatest_letter(letters, target):
    
    l = 0 
    r = len(letters) - 1
    
    while l < r:
        mid = (l + r) // 2
        
        # if mid < target:
        if ord(letters[mid]) <= ord(target):
            l = mid + 1
        elif ord(letters[mid]) > ord(target):
            r = mid
    
    if ord(letters[l]) <= ord(target):
        return letters[0]
        
    return letters[l]

letters = ['a', 'a', 'b', 'c', 'c', 'c', 'e', 'h', 'w']

print(next_greatest_letter(letters, 'a'))
print(next_greatest_letter(letters, 'd'))
print(next_greatest_letter(letters, 'y'))





