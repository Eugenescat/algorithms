
#  Concatenated Words（可拼接词）
# 给一个不重复的单词列表，找出其中所有能由至少两个列表中更短的单词首尾拼接而成的单词，按字母顺序返回。

def findAllConcatenated(words):
    word_set = set(words)
    result = []
    
    def canForm(word, start, count):
        if start == len(word):
            return count >= 2
        
        for end in range(start + 1, len(word) + 1):
            piece = word[start:end]
            if piece in word_set:
                if canForm(word, end, count + 1):
                    return True
        return False
    
    for word in words:
        if canForm(word, 0, 0):
            result.append(word)
    
    return result