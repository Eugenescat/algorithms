def  removeDuplicates(nums):
    n = len(nums)
    slow, fast = 0, 1
    while fast < n:
        if nums[fast] == nums[slow]:
            fast += 1
        else:
            slow += 1
            nums[slow] = nums[fast]
    return slow + 1