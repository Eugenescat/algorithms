import collections

# Word Ladder（单词接龙）题意：
# 给定 beginWord、endWord 和一个单词词典 wordList，每次只能改变一个字母，且每一步变出来的单词必须在词典里，求从 beginWord 到 endWord 最少经过几个单词（含起点终点）。若无法到达，返回 0。

def  ladderLength(beginWord, endWord, wordList):
    word_set = set(wordList)
    if endWord not in word_set:
        return 0
    
    queue = collections.deque()
    queue.append((beginWord, 1))
    visited = set()
    visited.add(beginWord)
    
    while queue:
        word, steps = queue.popleft()
        for i in range(len(word)):
            for j in "abcdefghijklmnopqrstuvwxyz":
                new_word = word[:i] + j + word[i + 1:]
                if new_word in visited:
                    continue
                visited.add(new_word)
                
                if new_word in word_set:
                    if new_word == endWord:
                        return steps + 1
                    else:
                        queue.append((new_word, steps + 1))
    
    return 0