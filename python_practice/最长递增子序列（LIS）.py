nums = [10, 9, 2, 5, 3, 7, 101, 18]
# 最长递增子序列：[2, 3, 7, 18] 或 [2, 5, 7, 18] 等
# 返回 4

dp = [1] * len(nums)
for i in range(len(nums)):
    for j in range(0, i, 1):
        if nums[j] < nums[i]:
            dp[i] = max(dp[i], dp[j] + 1)
            
print(max(dp))
        