class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(1,len(nums)):
            if nums[cnt] != nums[i]:
                nums[cnt+1] = nums[i]
                cnt += 1
        return cnt+1