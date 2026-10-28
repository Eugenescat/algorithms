
"""
A city network is described by an n x n matrix is_connected, 
where is_connected[i][j] == 1 means city i and city j are directly connected. 
A province is a group of cities that are directly or indirectly connected. 
Return the total number of provinces.

"""


def find_circle_num(is_connected):
    n = len(is_connected)
    parent = list(range(n))  
    
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    
    def union(x, y):
        a, b = find(x), find(y)
        if a != b:
            parent[a] = b
            return True
        return False

    
    provinces = n
    
    for i in range(n):
        for j in range(n):
            if is_connected[i][j] and union(i,j):
                provinces -= 1
    
    return provinces
        
# print(find_circle_num([[1, 1, 0], [1, 1, 0], [0, 0, 1]])) # 2
# print(find_circle_num([[1, 0, 0], [0, 1, 0], [0, 0, 1]])) # 3




"""
You start with a tree of n nodes labeled 1 to n, then one extra edge is 
added, creating exactly one cycle. Given the list of edges, return the 
one edge that can be removed so the graph is a tree again. If more than 
one answer exists, return the edge that appears last in the input.

"""

def find_redundant_connection(edges):
    parent = list(range(len(edges) + 1))
    
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    
    def union(u, v):
        x, y = find(u), find(v)
        if x != y:
            parent[x] = y
            return True
        return False
        
    for u, v in edges:
        if not union(u,v):
            return [u,v]
        


# print(find_redundant_connection([[1, 2], [1, 3], [2, 3]])) # [2, 3]
# print(find_redundant_connection([[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]])) # [1, 4]





def valid_tree(n, edges):
    parent = list(range(n))
    
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            parent[rx] = parent[ry]
            return True
        return False
    
    for u, v in edges:
        if not union(u,v):
            return False
    return True
    

#print(valid_tree(5, [[0, 1], [0, 2], [0, 3], [1, 4]])) # True
#print(valid_tree(5, [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]])) # False




"""
Given n nodes labeled 0 to n - 1 and a list of undirected edges, 
return the number of connected components in the graph.
"""


def count_components(n, edges):
    parent = list(range(n))
    
    def find(x):
        if x != parent[x]:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        r1, r2 = find(x), find(y)
        if r1 == r2:
            return False
    
        parent[r1] = r2
        return True

    res = n
    for x, y in edges:
        if union(x,y):
            res -= 1
    return res

#print(count_components(5, [[0, 1], [1, 2], [3, 4]])) # 2
#print(count_components(5, [[0, 1], [1, 2], [2, 3], [3, 4]])) # 1



"""
Each entry in accounts is a list of the form [name, email1, email2, ...]. 
Two accounts belong to the same person if they share at least one email 
(names alone do not merge them). Merge all accounts for the same person 
and return each merged account as the name followed by its emails in 
sorted order.

"""
from collections import defaultdict
def accounts_merge(accounts):
    parent = list(range(len(accounts)))
    
    def find(x):
        if x != parent[x]:
            parent[x] = find(parent[x])
        return parent[x]
    def union(x,y):
        r1, r2 = find(x), find(y)
        if r1 == r2:
            return False
        parent[r1] = r2
        return True
    
    owner = {} # email: person_idx
    
    for p, account in enumerate(accounts):
        for email in account[1:]:
            if email in owner:
                union(p, owner[email])
            else:
                owner[email] = p
    
    groups = defaultdict(list)
    for email, p in owner.items():
        groups[find(p)].append(email)
        
    res = []
    
    for root, emails in groups.items():
        name = accounts[root][0]
        res.append([name] + sorted(emails))
    res.sort()
    return res
    
    
        

accounts = [
    ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
    ["John", "johnsmith@mail.com", "john00@mail.com"],
    ["Mary", "mary@mail.com"],
    ["John", "johnnybravo@mail.com"],
]
# print(accounts_merge(accounts))
'''
[['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
 ['John', 'johnnybravo@mail.com'],
 ['Mary', 'mary@mail.com']]
'''



def remove_stones(stones):
    parent = list(range(len(stones)))
    
    def find(x):
        if x != parent[x]:
            parent[x] = find(parent[x])
        return parent[x]
    def union(x,y):
        r1, r2 = find(x), find(y)
        if r1 == r2:
            return False
        parent[r1] = r2
        return True
    
    n = len(stones)
    remaining = n
    for i in range(n):
        for j in range(i + 1, n):
            if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                if union(i, j):
                    remaining -= 1
    return n - remaining
                

print(remove_stones([[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]))
print(remove_stones([[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]))

