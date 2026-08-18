def  countSubstrings(s):
    n = len(s)
    dp = [[False] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = True
    res = n
    
    for i in range(1, n):
        if s[i] == s[i-1]:
            dp[i-1][i] = True
            res += 1
        if i >= 2 and s[i] == s[i-2]:
            dp[i-2][i] = True
            res += 1
        for j in range(i - 3, -1, -1):
            if s[j] == s[i] and dp[j+1][i-1]:
                dp[j][i] = True
                res += 1
    
    return res
                