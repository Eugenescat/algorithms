from collections import deque

## 注意这里要进行一个思维转换，不能是“删除list中若干特定下标对应的元素”（因为每次删除动作后，下标会变化），而是“收集list中不属于特定下标的其他有效元素”

def minRemoveToMakeValid(s):
    to_delete = []
    
    st = deque()
    for i in range(len(s)):
        if s[i] == '(':
            st.append(i)
        elif s[i] == ')':
            if i >= 1 and  s[i-1] == '(':
                to_delete.append(i)
                to_delete.append(i - 1)
                st.pop()
            elif not st:
                to_delete.append(i)
            else:
                st.pop()
                
    while st:
        to_delete.append(st[-1])
        st.pop()
        
    return [c for i, c in enumerate(s) if i not in to_delete]