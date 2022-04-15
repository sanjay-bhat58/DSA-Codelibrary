class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hmap = {}
        for i in range(len(nums)):
            hmap[nums[i]] = i
        for i in range(len(nums)):
            rem = target - nums[i]
            if rem in hmap:
                if hmap[rem] != i:
                    return [i,hmap[rem]]
            