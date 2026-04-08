
nums = list(map(int, input().split()))

def solution(nums: list):
    cur_sum = nums[0]
    max_sum = nums[0]
    for n in nums[1:]:
        cur_sum = max(cur_sum + n, n)
        max_sum = max(max_sum, cur_sum)
    return max_sum

solution(nums)