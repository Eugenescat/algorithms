from collections import defaultdict

def  findSubArrays(nums):

    res = []
    prefix = [0] * (len(nums) + 1)
    hmap = defaultdict(list)
    hmap[0].append(0)

    for i in range(len(nums)):

        prefix[i + 1] = prefix[i] + nums[i]

        hmap[prefix[i + 1]].append(i + 1)

    for presum, indexes in hmap.items():
        for i in range(len(indexes)):
            for j in range(i + 1, len(indexes)):
                res.append([indexes[i], indexes[j] - 1])
                
    res.sort()
    return res