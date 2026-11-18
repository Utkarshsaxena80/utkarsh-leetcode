class Solution(object):
    def subarraySum(self, nums, k):
        count=0
        curr=0
        mp={0:1}
        for num in nums:
            curr+=num
            count+=mp.get(curr-k,0)
            mp[curr]=mp.get(curr,0)+1
        return count
        