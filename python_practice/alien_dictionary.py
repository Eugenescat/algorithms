from collections import defaultdict
from typing import List
from collections import deque

class Solution:
    def alienOrder(self, words: List[str]) -> str:

        adj = defaultdict(list)
        in_degree = {char: 0 for word in words for char in word} # O(n)

        def findPrefixNext(a, b):
            i = 0
            while i < len(a) and i < len(b) and a[i] == b[i]:
                i += 1
            return i

        # build a graph: O(2n)
        for i in range(len(words) - 1):
            word = words[i]
            next_word = words[i + 1]
            x = findPrefixNext(word, next_word)
            # 容易忘记考虑"abc" "ab"的非法情形，如果忘记考虑就会全部当作indegree = 0
            if x < len(word) and x == len(next_word):
                return ""
            elif x < len(word) and x < len(next_word):
                adj[word[x]].append(next_word[x])
                in_degree[next_word[x]] += 1
        
        # topology sort: O(n)
        res = []
        queue = deque()
        for x, degree in in_degree.items():
            if degree == 0:
                queue.append(x)
        
        while queue:
            x = queue.popleft()
            res.append(x)
            for y in adj[x]:
                in_degree[y] -= 1
                if in_degree[y] == 0:
                    queue.append(y)
        
        for x, degree in in_degree.items():
            if degree != 0:
                return ""
        
        return "".join(res)
        