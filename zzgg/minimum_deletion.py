def  removeCharacters(str, dict):
    n = len(str)
    dp = [0] * (n + 1)
    
    def helper(index, word):
        j = index - 1
        i = len(word) -1
        start, end = -1, -1
        while j >= 0:
            if word[i] == str[j]:
                if i == len(word) - 1:
                    end = j
                elif i == 0:
                    start = j
                    break
                i -= 1
            j -= 1
            
        return (j >= 0, start, end)
    
    for i in range(1, n + 1): 
        dp[i] = dp[i - 1]    
        for word in dict:
            k = len(word)
            if i - k >= 0:
                exist, start, end = helper(i, word)
                if exist:
                    dp[i] = max(dp[i], dp[start] + k)
    return len(str) - dp[n]
        
str = "helloworbldbhelloaaa"
dict = ["hello", "world", "aa"]
print(removeCharacters(str, dict))