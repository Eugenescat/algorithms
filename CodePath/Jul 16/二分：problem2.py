def check_stock(inventory, part_id):
    # return true or false whether the part_id is in this window
    def recursive(start, end):
        if start == end:
            return inventory[start] == part_id
            
        mid = (start + end) // 2
        if inventory[mid] == part_id:
            return True
        elif inventory[mid] < part_id:
            return recursive(mid + 1, end)
        else:
            return recursive(start, mid)
    
    return recursive(0, len(inventory) - 1)

print(check_stock([1, 2, 5, 12, 20], 20))
print(check_stock([1, 2, 5, 12, 20], 100))