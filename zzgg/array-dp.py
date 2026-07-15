def  maxSubArray(nums):
    n = len(nums)
    if n == 0:
        return None
    init = float('-inf')
    dp = [init for _ in range(n)]
    dp[0] = nums[0]
    for i in range(1, n):
        dp[i] = max(nums[i], dp[i-1] + nums[i])
    
    return max(dp)