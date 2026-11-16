class Solution(object):
    def minMoves(self, nums):
        mini=min(nums)
        tot=0
        for i in range(0,len(nums)):
            tot+=nums[i]-mini
        return tot    


       
        