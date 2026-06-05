def sort_by_parity(nums):
    
    i = 0
    j = len(nums) - 1
    
    while i < j:
        # if it's odd, swap to the end, j to the next
        if nums[i] % 2 == 1:
            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            j -= 1
        # if it's even, i to the next
        else:
            i += 1
            
    
    return nums
        
        


if __name__ == "__main__":
    nums = [0]
    print(sort_by_parity(nums))