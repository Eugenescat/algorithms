from collections import Counter

def is_authentic_collection(art_pieces):
    n = max(art_pieces)
    if len(art_pieces) != n + 1:
        return False

    freq = Counter(art_pieces)
    for i in range(1, n):
        if freq[i] != 1:
            return False
    if freq[n] != 2:
        return False
    
    return True

collection1 = [2, 1, 3]
collection2 = [1, 3, 3, 2]
collection3 = [1, 1]

if __name__ == "__main__":
    print(is_authentic_collection(collection1))
    print(is_authentic_collection(collection2))
    print(is_authentic_collection(collection3))