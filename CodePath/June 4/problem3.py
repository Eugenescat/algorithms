problem3.py

from collections import defaultdict

def remove_dupes(items):
    
    # Goal : Find the no of unique items in the list after removing the duplicates
    
    # List = []
    if not items:
        return 0

    unquie = 1
    for i in range(1,len(items)):
        
        if items[i] != items[i-1]:
            unquie += 1
        else:    
            items[unquie] = items[i]
            
    return unquie
        

if __name__ == "__main__":
    items = ["extract of malt", "haycorns", "honey", "thistle"]
    print(remove_dupes(items))