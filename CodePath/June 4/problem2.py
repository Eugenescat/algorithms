problem2-2.py

# problem2.py

def reverse_list(lst):
    n = len(lst)
    i = 0
    j = n - 1
    
    while i < j:
        temp = lst[i]
        lst[i] = lst[j]
        lst[j] = temp
        
        i += 1
        j -= 1
        
    return lst

if __name__ == "__main__":
    lst = ["pooh", "christopher robin", "piglet", "roo", "eeyore"]
    print(reverse_list(lst))