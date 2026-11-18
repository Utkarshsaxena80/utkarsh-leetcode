class Solution(object):
    def subarraysDivByK(self, nums, k):
        #this speaks of prefix sum + hashmap 
        curr=0
        count=0
        mp={0:1}
        for num in nums:
            curr+=num
            rem=curr%k
            count+=mp.get(rem,0)
            mp[rem]=mp.get(rem,0)+1
        return count

        