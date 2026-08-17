
from collections import deque
def  nextGreaterElements(nums):
    n = len(nums)
    st = deque()
    res = [-1] * n
    
    for j in range(2*n-1, -1, -1):
        i = j % n
        k = nums[i]
        # print(k)
        if not st:
            st.append(i)
            # print(st)
        elif nums[st[-1]] > k:
            res[i] = nums[st[-1]]
            # print(f"res[{i}] = {res[i]}")
            st.append(i)
        else:
            while st and nums[st[-1]] <= k:
                # print("st[-1]: ", st[-1], "value: ", nums[st[-1]], "<= ", k, ", pop")
                st.pop()
            res[i] = nums[st[-1]] if st else -1
            # print(f"res[{i}] = {res[i]}")
            st.append(i)
            # print(st)
    
    return res