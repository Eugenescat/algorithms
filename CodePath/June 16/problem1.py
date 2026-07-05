"""
Understand:
    Input - String Is end Ds
    Output - String 
    Constraints - Only receive string.
    Edge Cases - 
        string is empty -> return '1'
Match:
Plan:
   1. Initialize an empty list `guest_order` to store the final order of guests.
2. Initialize an empty stack to help manage the digits as we process the `arrival_pattern`.
3. Iterate through the `arrival_pattern` from `0` to `n`, where `n` is the length of `arrival_pattern`:
   1. Push the digit `i + 1` onto the stack.
   2. If the current pattern character is `'I'` or we've reached the end of the pattern:
      1. Pop all elements from the stack and append them to `guest_order`.
4. Convert the `guest_order` list to a string and return it.

Implement:

Review:
Evaluate:

"""


def arrange_guest_arrival_order(arrival_pattern):
    n = len(arrival_pattern)
    guest_order = []
    st = []
    for i, op in enumerate(arrival_pattern):
        st.append(str(i + 1))
        if op == 'I':
            while st:
                guest_order.append(st.pop()) # pop from the end
        elif op == 'D':
            continue
    
    st.append(str(n + 1))
    while st:
        guest_order.append(st.pop())
    
    return ''.join(guest_order)
                

print(arrange_guest_arrival_order("IIIDIDDD"))  # 123549876
print(arrange_guest_arrival_order("DDD")) # 4321  