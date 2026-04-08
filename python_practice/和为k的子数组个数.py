
def solution(nums:list, k:int):
    res = 0
    # 前缀和
    prefix = 0
    map = dict()
    map[0] = 1
    for i in range(len(nums)):
        prefix += nums[i]
        res += map.get(prefix - k, 0) # 防止map中key不存在时出现keyError
        map[prefix] = map.get(prefix, 0) + 1 # 防止map中key不存在时出现keyError
    return res
    
    