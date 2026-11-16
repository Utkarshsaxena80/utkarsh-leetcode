class Solution(object):
    def minMoves(self, nums):
        maxi=max(nums)
        tot=0
        for num in nums:
            tot+=maxi-num
        return tot