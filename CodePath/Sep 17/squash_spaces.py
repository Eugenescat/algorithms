
# time: O(n) space: O(n)

def squash_spaces(s):
    seen_white = False
    res = list(s)
    i = j = 0
    while j < len(s):
        if res[j] == " " and not seen_white:
            seen_white = True #cheers!!!
            res[i] = " "
            i += 1
        elif res[j] != " ":
            seen_white = False
            res[i] = res[j]
            i += 1
        j += 1
    
    if res[0] == ' ':
        start = 1
    else:
        start = 0
    # i points to the next
    if res[i-1] == ' ':
        end = i - 1
    else:
        end = i
    return "".join(res[start:end])
    

s = "   Up,     up,   and  away! "
print(squash_spaces(s))

s = "With great power comes great responsibility."
print(squash_spaces(s))
