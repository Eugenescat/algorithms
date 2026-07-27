def  longestPalindromeSub(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 1
    
    # 这里要按区间长度来做外层循环，不能习惯性地i in range(n), i in range(j)
    # 因为状态转移方程是由外而内的：dp[j][i] = dp[j+1][i-1] + 2
    for length in range(2, n + 1):
        for i in range(n):
            j = i + length - 1
            if j > n - 1:
                break
            if s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1] + 2
            else:
                dp[i][j] = max(dp[i][j-1], dp[i+1][j])
    
    return dp[0][n-1]